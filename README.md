This project is a collection of tools to help interface with [GTFS](https://gtfs.org/) data.

This project is broken out by language. Each language provides its own functionality for interfacing with GTFS data.

### C++
Right now, just has a parser for reading in a file that's of the binary GTFS-Realtime format.
I absolutely could not find any implementation online that did this, so I'm uploading what I have in case its useful.

### SQL
This mostly contains just some helpful information to get the data you need from GTFS files.

## Usage

### Compiling

#### Option 1: Automatic Installation

I've created a script to install (only tested for Mac OS Monterey 12.1)

```
source install-cpp.sh
install-protobuf
generate-gtfs-realtime
```

#### Option 2: Manual
Before running, you'll need to install protobuf. Instructions on installing it can be found in the [GTFS Repo](https://github.com/protocolbuffers/protobuf). Since this project primarily supports C++, those instructions can be found [here](https://github.com/protocolbuffers/protobuf/blob/main/src/README.md).

Obtain the latest version of Protobuf from the [Protobuf releases page](https://github.com/protocolbuffers/protobuf/releases)

#### Option 3: Homebrew

You can install Protobuf using homebrew: brew install protobuf