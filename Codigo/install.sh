#sudo apt update
sudo apt install build-essential

gcc serverUDP.c -o servidor -lpthread -lm
gcc clientUDP.c -o cliente -lpthread





# Terminal 1
./servidor 5000

# Terminal 2
./cliente 127.0.0.1 "CommTest!" 5000
