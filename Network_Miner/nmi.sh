#!/bin/bash
sudo apt-get install libmono-system-windows-forms4.0-cil
sudo apt-get install libmono-system-web4.0-cil
sudo apt-get install libmono-system-net4.0-cil
sudo apt-get install libmono-system-runtime-serialization4.0-cil
sudo apt-get install libmono-system-xml-linq4.0-cil
wget www.netresec.com/?download=NetworkMiner -O /tmp/nm.zip
sudo unzip /tmp/nm.zip -d /opt/
cd /opt/NetworkMiner*
sudo chmod +x NetworkMiner.exe
sudo chmod -R go+w AssembledFiles/
sudo chmod -R go+w Captures/
