import matplotlib.pyplot as plt
import numpy as np

compiled = 40
not_compiled = 300

success = 6
fail = 30

def main():
    labels1 = ["Compiled", "Error in compile"]
    values1 = [compiled, not_compiled]

    labels2 = ["Succeeds on tests", "Fails on tests"]
    values2 = [success, fail]

    fig, axes = plt.subplots(1, 2, figsize=(10, 6))

    # Left: compilation counts
    ax = axes[0]
    x1 = np.arange(len(labels1))
    bars1 = ax.bar(x1, values1, color=["#4CAF50", "#F44336"])
    # bars1 = ax.bar(x1, values1, color=["#2196F3", "#FFC107"])
    ax.set_xticks(x1)
    ax.set_xticklabels(labels1)
    ax.set_title(f"Compilation: {100 * compiled / (compiled + not_compiled):.2f}%")
    for b in bars1:
        ax.annotate(
            str(int(b.get_height())),
            xy=(b.get_x() + b.get_width() / 2, b.get_height()),
            xytext=(0, 3),
            textcoords="offset points",
            ha="center",
            va="bottom",
        )

    # Right: test results
    ax = axes[1]
    x2 = np.arange(len(labels2))
    bars2 = ax.bar(x2, values2, color=["#4CAF50", "#F44336"])
    ax.set_xticks(x2)
    ax.set_xticklabels(labels2)
    ax.set_title(f"Test Results: {100 * success / (success + fail):.2f}%")
    for b in bars2:
        ax.annotate(
            str(int(b.get_height())),
            xy=(b.get_x() + b.get_width() / 2, b.get_height()),
            xytext=(0, 3),
            textcoords="offset points",
            ha="center",
            va="bottom",
        )

    plt.tight_layout(pad=2.5)
    fig.savefig("graphics_out.png")
    print("Saved plot to graphics_out.png")
    plt.show()

if __name__ == "__main__":
    main()