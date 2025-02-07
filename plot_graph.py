import pandas as pd
import matplotlib.pyplot as plt

# Read CSV file
df = pd.read_csv("results.csv")

# Plot execution times
plt.figure(figsize=(10, 6))
plt.plot(df["TestCase"], df["Function1"], marker='o', label="Function 1")
plt.plot(df["TestCase"], df["Function2"], marker='s', label="Function 2")
plt.plot(df["TestCase"], df["Function3"], marker='^', label="Function 3")

plt.xlabel("Test Case")
plt.ylabel("Execution Time (seconds)")
plt.title("Execution Time Comparison of Functions")
plt.legend()
plt.grid(True)
plt.savefig("benchmark_plot.png")  # Save the plot as an image
plt.show()
