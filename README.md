# wavgen
Generate reference sound samples

## Features
- generate wave samples (currently RAW format only)
- support for LE16, BE16 and FLOAT 
- define the signal frequency, amplitude, sample rate and duration

## Building wavegen
Requires the [TCLAP][10] parser and `TCLAP_HOME` environment variable
set to directory containing [TCLAP][10].

Example:

	$ TCLAP_HOME="${HOME}/tclap-1.2.1" make

## Todo
- adjust the sample length to contain integral amount of signal periods


Copyright &copy; 2016 [Przemysław Podwapiński][98].<br>
Distributed under the [Simplified BSD License][99].

[10]:http://tclap.sourceforge.net/
[98]:mailto:p.podwapinski@gmail.com
[99]:https://www.freebsd.org/copyright/freebsd-license.html

