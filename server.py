import socket

def main():
    port = 51234
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind(("0.0.0.0", port))
    server_socket.listen(10)
    print(f"Server listening on port {port}")

    while True:
        client_sock, addr = server_socket.accept()
        print(f"New connection from {addr}")
        client_sock.close()

if __name__ == "__main__":
    main()