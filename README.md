[![Build Status](https://travis-ci.com/TTitcombe/Casset.svg?branch=master)](https://travis-ci.com/TTitcombe/Casset)
[![Total alerts](https://img.shields.io/lgtm/alerts/g/TTitcombe/Casset.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/TTitcombe/Casset/alerts/)
# Casset

Casset (C++ Asset management) allows for tracking, comparison, and analysis of portfolios of stocks and bonds.
Casset currently fetches stock data using IEX api.


## Getting Started

### Prerequisites
Install [CMAKE](https://cmake.org/)
Install [Conan](https://conan.io/)
Once you have installed [Conan](https://conan.io/), you need to add the following remotes using ```conan remote add x y``` where x is the local name for the remote and y is path to the remote:
* zimmerk https://api.bintray.com/conan/zimmerk/conan
* bincrafters https://api.bintray.com/conan/bincrafters/public-conan
* vthiery https://api.bintray.com/conan/vthiery/conan-packages
* cli11 https://api.bintray.com/conan/cliutils/CLI11

NOTE: Due to an issue in the current conan/cmake setup, Windows builds MUST be in Release for the time being.

## Building
Clone this repository and build in cmake.

## How to use
Once you have Casset, build Casset.sln.
You can run the compiled Casset with the command following command line arguments:
* **-s** or **--symbol**. A stock ticker symbol for which data will be retrieved. Default is "AAPL".
* **-l** or **--loglevel**. A string describing the logging level. Default is "info".

Running Casset with a valid ticker symbol (e.g. `AAPL`) will print out the most recent data associated with that company, including
open, high, close prices, and the date to which the data pertains.

*Note: The ticker symbols must be in upper case.*

## Running the tests

## Deployment


## Built With

* [CMAKE](https://cmake.org/) - Cross platform makefile generation
* [Conan](https://conan.io/) - Package manager for C++

## Contributing

Refer to [the contribution docs](CONTRIBUTING.md)


## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/ess-dmsc/project/tags).

## Authors

* **Tom Titcombe** - *Initial work* - [TTitcombe](https://github.com/TTitcombe)
* **Matthew Jones** - *Initial work and project guidance* - [matthew-d-jones](https://github.com/matthew-d-jones)

## License

This project is licensed under the BSD 2-Clause License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Thank you to Matthew Jones for mentoring throughout this project
