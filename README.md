# GrADS 2.0.x FreeBSD Port  
This is a port for GrADS 2.0.x

## Getting Started
This is by no means complete as of this writing it is compiling without errors but it dependencies are not automatic.
I have no knowledge that this is actually producing working grads binary other than I am able to run 'q config'

One of the dependences is not even in ports (g2clib) yet.

### Prerequisites
Some of these are probably unneeded and some are already added into the dependency list, but in an effort to have
the requirements documented this is a blanket installation of package

```
pkg install lang/gcc5 devel/gmake science/udunits x11/libsx graphics/gd devel/readline graphics/cairo \
ftp/curl science/netcdf graphics/libgeotiff devel/shapelib science/grib_api graphics/jasper
```

#### g2clib
```
fetch g2clib build and install. This should be converted to a port


fetch http://www.nco.ncep.noaa.gov/pmb/codes/GRIB2/g2clib-1.6.0.tar
tar xf g2clib-1.6.0.tar
cd g2clib-1.6.0
remove '-D__64BIT__' from the CFLAGS listed in 'makefile'
gmake

cp libg2c_v1.6.0.a /usr/local/lib/
ln -s /usr/local/lib/libg2c_v1.6.0.a /usr/local/lib/libgrib2c.a
cp grib2.h /usr/local/include
```

### Build grads2
This is a FreeBSD port so check this out to /usr/port/graphics/grads2 and run make && make install

