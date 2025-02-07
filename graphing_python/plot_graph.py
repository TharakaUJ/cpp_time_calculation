import pandas as pd
import matplotlib.pyplot as plt

# Read CSV file
df = pd.read_csv("./../results.csv")

# Plot execution times
plt.figure(figsize=(10, 6))
plt.plot(df["TestCase"], df["insersion_sort"], marker='o', label="insersion_sort")
plt.plot(df["TestCase"], df["bubble_sort"], marker='s', label="bubble_sort")
plt.plot(df["TestCase"], df["optimized_bubble_sort"], marker='^', label="optimized_bubble_sort")
plt.plot(df["TestCase"], df["selection_sort"], marker='*', label="selection_sort")

# Add labels and title
plt.xlabel("Test Case")
plt.ylabel("Execution Time (seconds)")
plt.title("Execution Time Comparison of Functions")
plt.legend()
plt.grid(True)
plt.savefig("benchmark_plot.png")  # Save the plot as an image
plt.show()
