#!/bin/bash
if [[ `python3 --version` != *"Python 3."* ]]; then
  echo "Python3 is required. Please make sure you have also installed python-dev, python-tk and python-venv. 'python3' command should default to python 3.x"
  # This can be installed by e.g.  sudo apt-get -y install gcc make build-essential libssl-dev libffi-dev python3 python3-dev python3-venv
else
  echo "Creating and activating virtual environment for Python3"
  python3 -m venv venv
  source venv/bin/activate

  echo "Installing all required python packages"
  pip install --upgrade pip
  pip install Cython numpy scipy h5py pandas sklearn matplotlib jupyter tqdm ipdb scikit-optimize psutil

  echo -e "\n\nCompiling Cython code \n\n"
  cd detection_localisation
  python3 setup.py build_ext --inplace
  cd ..
fi