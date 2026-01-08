killall gnome-terminal-server

gnome-terminal -- bash -c "../Codigo/servidor 5000; exec bash"
gnome-terminal -- bash -c "../Codigo/cliente 127.0.0.1 OpenValve#13#99! 5000; exec bash"
