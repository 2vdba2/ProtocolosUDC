killall gnome-terminal-server

gnome-terminal -- bash -c "../Codigo/serverUDP 5000; exec bash"
gnome-terminal -- bash -c "../Codigo/clientUDP 127.0.0.1 OpenValve#13#99! 5000; exec bash"
