#!/bin/bash
wget https://github.com/sans-dfir/sift-cli/releases/download/v1.6.1/sift-cli-linux # download sift CLI
wget https://github.com/sans-dfir/sift-cli/releases/download/v1.6.1/sift-cli-linux.sha256.asc # hash for integ check
gpg --keyserver pgp.mit.edu --recv-keys 22598A94 # Get GPG key for hash check
gpg --verify sift-cli-linux.sha256.asc # GPG verification of hash
sudo mv sift-cli-linux /usr/local/bin/sift # move sift to /bin for command line execution
chmod 755 /usr/local/bin/sift # set permissions
sift install # install sift
