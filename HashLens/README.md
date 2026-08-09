# HashLens

**HashLens** is a C++ command-line tool for hash identification and analysis.

The project is being developed as part of my engineering foundations and cybersecurity portfolio, with the goal of gradually expanding it into a more complete hash analysis tool.

## Current Features

* Interactive command-line interface
* Hash inspection workflow
* User confirmation before identification
* Hexadecimal validation
* Hash length-based identification
* Supports identification of:

  * MD5
  * SHA-1
  * SHA-256
  * SHA3-256
  * SHA-512
  * SHA3-512
* Handles unknown/custom hash formats
* Windows console color output
* ASCII banners for the main application, inspection stage, and identification stage

## Current Workflow

```text
HashLens
   │
   ├── Start hash inspection? (Y/N)
   │
   ├── Hash Inspector
   │      │
   │      ├── Enter hash
   │      ├── Display received hash
   │      └── Proceed with identification? (Y/N)
   │
   └── Hash Identifier
          │
          ├── Validate hexadecimal characters
          ├── Check hash length
          └── Display possible hash type
```

## Hash Identification Logic

| Length | Possible Hash Type |
| -----: | ------------------ |
|     32 | MD5                |
|     40 | SHA-1              |
|     64 | SHA-256 / SHA3-256 |
|    128 | SHA-512 / SHA3-512 |
|  Other | Unknown / Custom   |

> Hash identification based on length is not guaranteed to uniquely determine the algorithm. Multiple algorithms can produce hashes of the same length.

## Project Structure

```text
HashLens/
├── include/
│   ├── HashInspector.h
│   └── HashIdentifier.h
├── src/
│   └── main.cpp
├── tests/
├── docs/
├── screenshots/
└── README.md
```

## Technologies

* C++
* GCC / MinGW
* Windows API
* Visual Studio Code
* Git / GitHub

## Example

```text
Start hash inspection? (Y/N): y

Enter hash: 5d41402abc4b2a76b9719d911017c592

Hash received: 5d41402abc4b2a76b9719d911017c592

Proceed with hash identification? (Y/N): y

Possible hash type: MD5
```

## Roadmap

Planned improvements include:

* More robust hash identification
* Additional hash algorithms
* Hash cracking functionality
* Wordlist support
* Hash generation
* Better error handling
* Automated testing
* Improved CLI interface
* Hash analysis and metadata
* Documentation and usage examples

## Status

**Version:** 1.0.0

**Current stage:** Hash inspection and basic identification

This project is actively being developed.
