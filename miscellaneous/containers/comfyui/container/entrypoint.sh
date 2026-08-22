#!/bin/bash

echo "initializing..."

cd /repository/ComfyUI/
if [ ! -f /work/setup_done.txt ]; then
    echo "Running setup..."
    pip3 uninstall -y torch torchvision torchaudio
    #pip3 install torch torchvision torchaudio --index-url https://pytorch.org
    #pip3 install torch torchvision torchaudio --extra-index-url https://download.pytorch.org/whl/cu130
    pip3 install --pre torch torchvision torchaudio --index-url https://download.pytorch.org/whl/nightly/cu132

    pip3 install -r requirements.txt
    pip3 install -r custom_nodes/ComfyUI-Manager/requirements.txt
    touch /work/setup_done.txt
else
    echo "Setup already completed. Skipping pip installations."
fi

echo "start App."
python3 main.py --listen --lowvram --enable-dynamic-vram
