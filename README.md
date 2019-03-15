[![Build Status](https://travis-ci.com/TTitcombe/Casset.svg?branch=master)](https://travis-ci.com/TTitcombe/Casset)
# Casset

Casset (C++ Asset management) allows for tracking, comparison, and analysis of portfolios of stocks and bonds.
Casset currently fetches stock data using IEX api.

## How to use
Once you have Casset (see below), build Casset.sln. This will open a command prompt which asks for your IEX key.
Upon entering your IEX key, Casset will attend to get the latest Apple stock data.

## Getting Started
Clone this repository and build the target "Casset" with cmake 
```cmake Casset```

### Prerequisites
Install [CMAKE](https://cmake.org/)
Install [Conan](https://conan.io/)
Once you have installed [Conan](https://conan.io/), you need to add the following remotes using ```conan remote add x y``` where x is the local name for the remote and y is path to the remote:
* zimmerk https://api.bintray.com/conan/zimmerk/conan
* bincrafters https://api.bintray.com/conan/bincrafters/public-conan

Get an [IEX account](https://iexcloud.io/) and make a note of your keys.

### Installing
Clone this repository and build it with CMake (preferable in a directory outside your source)

NOTE: Due to an issue in the current conan/cmake setup, Windows builds MUST be in Release for the time being.

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
