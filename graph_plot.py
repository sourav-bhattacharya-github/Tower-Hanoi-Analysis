import pandas as pd
import matplotlib.pyplot as plt

# Load CSV file
data = pd.read_csv("hanoi_times.csv")

# Plot graph
plt.figure(figsize=(8,6))
plt.plot(data["Disks"], data["Time(seconds)"], marker='o', linestyle='-', color='b', label="Execution Time")

# Labels and title
plt.xlabel("Number of Disks (n)")
plt.ylabel("Execution Time (seconds)")
plt.title("Tower of Hanoi: Execution Time vs Number of Disks")
plt.grid(True)
plt.legend()

# Show plot
plt.show()
