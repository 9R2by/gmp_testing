import secrets


def generate_random_bytes(length):
    print("Random Bytes:", secrets.token_hex(length).upper())


if __name__ == "__main__":
    generate_random_bytes(16)
