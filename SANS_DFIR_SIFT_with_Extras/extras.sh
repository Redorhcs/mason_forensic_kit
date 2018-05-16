#!/bin/bash
git clone https://github.com/mkorman90/VolatilityBot.git
cd VolatilityBot/
pip install -r requirements.txt
cd ..
pip install PyPDF2==1.26.0
pip install olefile==0.44
pip install lxml==3.7.3
git clone https://github.com/MonroCoury/Forensic-Tools.git
cd Forensic-Tools
pip install -r requirements.txt
