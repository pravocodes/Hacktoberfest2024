import pandas as pd
import time
import os
from faker import Faker
import matplotlib.pyplot as plt
fake = Faker()
data = []
for _ in range(100000):  # Generate 100,000 records
    data.append({
        'name': fake.name(),
        'address': fake.address(),
        'email': fake.email(),
        'date_joined': fake.date(),
        'salary': fake.random_number(digits=5)
    })
df = pd.DataFrame(data)
def write_csv(df, filename):
    start = time.time()
    df.to_csv(filename, index=False)
    return time.time() - start

def write_parquet(df, filename):
    start = time.time()
    df.to_parquet(filename)
    return time.time() - start
def read_csv(filename):
    start = time.time()
    df = pd.read_csv(filename)
    return time.time() - start

def read_parquet(filename):
    start = time.time()
    df = pd.read_parquet(filename)
    return time.time() - start
csv_file = 'data.csv'
parquet_file = 'data.parquet'
write_times = {
    'CSV': write_csv(df, csv_file),
    'Parquet': write_parquet(df, parquet_file)
}
read_times = {
    'CSV': read_csv(csv_file),
    'Parquet': read_parquet(parquet_file)
}
labels = ['CSV', 'Parquet']
write_times_values = [write_times['CSV'], write_times['Parquet']]
read_times_values = [read_times['CSV'], read_times['Parquet']]
# Plotting
x = range(len(labels))
width = 0.35  # Width of bars

fig, ax = plt.subplots()
ax.bar(x, write_times_values, width, label='Write Time (seconds)', color='b')
ax.bar([p + width for p in x], read_times_values, width, label='Read Time (seconds)', color='g')

# Adding labels and title
ax.set_xlabel('File Formats')
ax.set_ylabel('Time (seconds)')
ax.set_title('Comparison of Read/Write Times for CSV and Parquet')
ax.set_xticks([p + width / 2 for p in x])
ax.set_xticklabels(labels)
ax.legend()

# Show the plot
plt.tight_layout()
plt.show()
