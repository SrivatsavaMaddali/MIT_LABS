import sqlite3

conn = sqlite3.connect('registration.db')

conn.execute('''CREATE TABLE IF NOT EXISTS users 
                 (id INTEGER PRIMARY KEY AUTOINCREMENT, 
                  username TEXT NOT NULL UNIQUE,
                  email TEXT NOT NULL UNIQUE,
                  password TEXT NOT NULL);''')

def register_user():
    username = input("Enter username: ")
    email = input("Enter email address: ")
    password = input("Enter password: ")

    if not username.isalnum():
        print("Error: Username can only contain letters and numbers.")
        return
    if not email.count("@"):
        print("Error: Invalid email address.")
        return
    if len(password) < 8:
        print("Error: Password must be at least 8 characters long.")
        return

    try:
        conn.execute("INSERT INTO users (username, email, password) VALUES (?, ?, ?)", (username, email, password))
        conn.commit()
        print("User registered successfully!")
    except sqlite3.IntegrityError:
        print("Error: Username or email already exists.")

register_user()

conn.close()
