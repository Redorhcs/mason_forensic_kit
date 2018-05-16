#!/bin/bash
# VOlatility Bot, automated mem forensics
git clone https://github.com/mkorman90/VolatilityBot.git
cd VolatilityBot/
pip install -r requirements.txt
cd ..
pip install PyPDF2==1.26.0
pip install olefile==0.44
pip install lxml==3.7.3
# FOrensic TOols, some python scripts
git clone https://github.com/MonroCoury/Forensic-Tools.git
cd Forensic-Tools
# pip install -r requirements.txt
#
# DOmain Enumerator
git clone https://github.com/diogo-fernan/domfind.git
cd domfind
pip install -r requirements.txt
