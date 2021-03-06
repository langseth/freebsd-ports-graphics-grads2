# Created by: Greg Lewis <glewis@FreeBSD.org>
# $FreeBSD: head/graphics/grads/Makefile 452602 2017-10-21 20:18:16Z sunpoet $

PORTNAME=	grads
PORTVERSION=	2.2.0
PKGNAMESUFFIX=	2
#PORTREVISION=	12
CATEGORIES=	graphics science math
MASTER_SITES=	ftp://cola.gmu.edu/grads/2.2/:src \
		ftp://grads.iges.org/grads/:other \
		ftp://cola.gmu.edu/grads/:other
DISTFILES=	${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX}:src \
		example.tar.gz:other
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX}

MAINTAINER=	gf-admins@iteris.com
COMMENT=	The Grid Analysis and Display System

BUILD_DEPENDS=	${LOCALBASE}/lib/libudunits2.a:science/udunits \
		${LOCALBASE}/lib/libsx.a:x11/libsx
LIB_DEPENDS=	libgd.so:graphics/gd \
		libpng.so:graphics/png \
		libX11.so:x11/libX11 \
		libcairo.so:graphics/cairo

USES=		readline jpeg ncurses
USE_GCC=	any
GNU_CONFIGURE=		yes
LDFLAGS=			-L/usr/lib -lz -lsz -L/usr/local/lib  -lX11
CONFIGURE_ENV+=		SUPPLIBS="${LOCALBASE}"
CONFIGURE_ARGS+=	--enable-dyn-supplibs \
			--with-readline \
			--with-geotiff \
			--with-grib2 \
			--with-gui \
			--with-x \
			--with-cairo

OPTIONS_DEFINE=	HDF NETCDF DOCS EXAMPLES
OPTIONS_DEFAULT=	NETCDF
HDF_DESC=	Build hdf-support (only hdf OR netcdf is supported)
NETCDF_DESC=	Build netcdf-support

PORTDATA=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*
.endif

.if ${PORT_OPTIONS:MHDF}
BROKEN=			Fails to package
LIB_DEPENDS+=		libmfhdf.so:science/hdf
CONFIGURE_ARGS+=	--with-hdf
PLIST_SUB+=		NETCDF="@comment " HDF=""
.endif

.if ${PORT_OPTIONS:MNETCDF}
LIB_DEPENDS+=		libnetcdf.so:science/netcdf
CONFIGURE_ARGS+=	--with-netcdf
PLIST_SUB+=		NETCDF="" HDF="@comment "
.endif

post-extract:
	${MKDIR} "${WRKSRC}/examples"
	cd "${WRKSRC}/examples" && ${TAR} -xzf "${DISTDIR}/example.tar.gz"

post-configure:
	${REINPLACE_CMD} -e "s:%%DATADIR%%:${DATADIR}:" ${WRKSRC}/src/gx.h

post-install:
	${MKDIR} "${STAGEDIR}${DATADIR}"
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . "${STAGEDIR}${DATADIR}"
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} "${STAGEDIR}${EXAMPLESDIR}"
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . "${STAGEDIR}${EXAMPLESDIR}"
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} "${STAGEDIR}${DOCSDIR}"
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . "${STAGEDIR}${DOCSDIR}"
.endif

.include <bsd.port.mk>
