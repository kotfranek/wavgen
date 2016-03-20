# wavgen
Generate reference wave signal samples

## Features
- generate wave samples:
 - sine
 - triangle
 - saw
 - square
- define signal parameters:
 - frequency
 - amplitude
 - sample rate
 - duration 
- store as LE16, BE16 and FLOAT
 - currently raw data only

## Building wavegen
Requires the [TCLAP][10] parser and `TCLAP_HOME` environment variable
set to directory containing [TCLAP][10].

Example:

```sh
TCLAP_HOME="${HOME}/tclap-1.2.1" ./configure.sh
```

## Todo
- adjust the sample length to contain integral amount of signal periods


Copyright &copy; 2016 [Przemysław Podwapiński][98].<br>
Distributed under the [Simplified BSD License][99].

[10]:http://tclap.sourceforge.net/
[98]:mailto:p.podwapinski@gmail.com
[99]:https://www.freebsd.org/copyright/freebsd-license.html
