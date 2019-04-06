[![Build Status](https://travis-ci.com/TTitcombe/Casset.svg?branch=master)](https://travis-ci.com/TTitcombe/Casset)
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

NOTE: Due to an issue in the current conan/cmake setup, Windows builds MUST be in Release for the time being.

## Building
Clone this repository and build in cmake.

## How to use
Once you have Casset, build Casset.sln. This will open a command prompt which asks for a stock ticker.
Entering a valid ticker symbol (e.g. `AAPL`) will print out the most recent data associated with that company, including
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

## License

This project is licensed under the BSD 2-Clause License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc
