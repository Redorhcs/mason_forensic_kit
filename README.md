# George Mason PreCollege Cyber Security Program Forensic Toolkit

Premade installation scripts for common tools et al that are used in the Forensic Process.

## Description

After installing the same virtual machine and their associated tools for the twentith* time, we decided to automate it finally. From there, this project was formed. All scripts are self-documentating, and are known to run on at least Ubuntu 18.04 (with the exception of Windows executables)

## Getting Started

### Dependencies

* Ubuntu 18.04
* Git
* Internet connection

### Installing

* Downloads can be grabbed from either the releases page, or a straight-up clone if you're adventerous
* Scripts may require `chmod +x <scriptName>` to execute

### Executing program

#### SANS DFIR SIFT
* Navigate to the install directory
* Execute
```
sudo ./sift.sh
```

#### SANS DFIR SIFT
* Navigate to the install directory
* Execute
```
sudo ./sift.sh
```
* Aditional (optional) python tools can be installed via 
```
sudo ./extras.sh
```

##### SNORT on Ubuntu 18.04
* Inside the SANS folder, execute 
```
sudo ./snort_specific_install
```
* Provide a registered user Oinkcode to download the ruleset
* After installation, test with (inside the same directory as snort.conf)
```
sudo snort -T -c snort.conf
```

### SNORT Windows
A copy of Snort 2.9.11.x with a working configuration for PCAP analysis and general use. Currently has the reputation preprocessor disabled, with plans to enable.

### network_miner_on_kali
A very simple shell script to process the installation of NetworkMiner. Adapated from https://www.netresec.com/?page=Blog&month=2014-02&post=HowTo-install-NetworkMiner-in-Ubuntu-Fedora-and-Arch-Linux

## Authors

Contributors names and contact info

  [RS Tyler Schroder](https://redcoded.com) | @Redorhcs  
  David Rudo | @1CoolDavid

## Version History

* 0.1
    * Initial Release

## License

This project is licensed under the GPL-3.0 License - see the LICENSE file for details

## Acknowledgments

* [awesome-readme](https://github.com/matiassingers/awesome-readme)
