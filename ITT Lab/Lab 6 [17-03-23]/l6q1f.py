import os

env_vars = os.environ

for var in env_vars:
    print(f"{var}: {env_vars[var]}")
