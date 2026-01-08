#sudo apt update
sudo apt install build-essential

gcc serverUDP.c -o servidor -lpthread -lm
gcc clientUDP.c -o cliente -lpthread
