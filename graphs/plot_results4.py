import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import numpy as np

simple_key = "Simple"
cot_key = "Chain-of-Thought"

# ── shared style ──────────────────────────────────────────────────────────────
COLORS = {simple_key: "#4C9BE8", cot_key: "#E8834C"}
BAR_W  = 0.35

def style_ax(ax, title, ylabel):
    # ax.set_title(title, fontsize=11, fontweight="bold", pad=8)
    ax.set_ylabel(ylabel, fontsize=9)
    ax.spines[["top", "right"]].set_visible(False)
    ax.yaxis.grid(True, linestyle="--", alpha=0.5)
    ax.set_axisbelow(True)
    legend = [mpatches.Patch(facecolor=COLORS[simple_key], edgecolor="black", linewidth=0.8, label=simple_key),
              mpatches.Patch(facecolor=COLORS[cot_key],   edgecolor="black", linewidth=0.8, label=cot_key)]
    ax.legend(handles=legend, fontsize=8)

def plot_bars(ax, xs, labels, simple_vals, plan_vals):
    b1 = ax.bar(xs - BAR_W/2, simple_vals, BAR_W,
                color=COLORS[simple_key], edgecolor="black", linewidth=0.8, zorder=3)
    b2 = ax.bar(xs + BAR_W/2, plan_vals,   BAR_W,
                color=COLORS[cot_key],   edgecolor="black", linewidth=0.8, zorder=3)
    ylim_top = max(max(simple_vals), max(plan_vals)) * 1.15
    ax.set_ylim(0, ylim_top)
    # for bars in (b1, b2):
    #     for bar in bars:
    #         h = bar.get_height()
    #         ax.text(bar.get_x() + bar.get_width() / 2, h + ylim_top * 0.01,
    #                 f"{h:g}", ha="center", va="bottom", fontsize=8)
    ax.set_xticks(xs)
    ax.set_xticklabels(labels, fontsize=9)

# ── data (incorrect columns removed) ─────────────────────────────────────────
compile_data = {
    simple_key: {"sources": 196, "compiled": 122},
    cot_key:   {"sources": 122, "compiled": 78},
}

bench_data = {
    simple_key: {"tested programs": 100, "correct": 39},
    cot_key:   {"tested programs": 63, "correct": 27},
}

misc_data = {
    simple_key: {"avg lines\nof code": 80.38, "avg lines\nof comments": 56.10},
    cot_key:   {"avg lines\nof code": 87.15, "avg lines\nof comments": 17.59},
}

prompt_data = {
    simple_key: {"input responses": 208, "extracted": 196},
    cot_key:   {"input responses": 208, "extracted": 122},
}

# ── single 2×2 figure ────────────────────────────────────────────────────────
fig, axes = plt.subplots(1, 3, figsize=(14, 4))
# fig, axes = plt.subplots(2, 2, figsize=(12, 8))
# fig.suptitle("Benchmark Overview", fontsize=14, fontweight="bold", y=1.01)

# 1. Prompt Extraction
ax = axes[0]
# ax = axes[0, 0]
labels = list(prompt_data[simple_key].keys())
xs = np.arange(len(labels))
plot_bars(ax, xs, labels,
          list(prompt_data[simple_key].values()),
          list(prompt_data[cot_key].values()))
style_ax(ax, "Prompt Extraction", "Count")

# 2. Compile
ax = axes[1]
# ax = axes[0, 1]
labels = list(compile_data[simple_key].keys())
xs = np.arange(len(labels))
plot_bars(ax, xs, labels,
          list(compile_data[simple_key].values()),
          list(compile_data[cot_key].values()))
style_ax(ax, "Compile Results", "Count")

# 3. Benchmark
ax = axes[2]
# ax = axes[1, 0]
labels = list(bench_data[simple_key].keys())
xs = np.arange(len(labels))
plot_bars(ax, xs, labels,
          list(bench_data[simple_key].values()),
          list(bench_data[cot_key].values()))
style_ax(ax, "Benchmark Results", "Count")

# # 4. Misc
# ax = axes[1, 1]
# labels = list(misc_data[simple_key].keys())
# xs = np.arange(len(labels))
# plot_bars(ax, xs, labels,
#           list(misc_data[simple_key].values()),
#           list(misc_data[cot_key].values()))
# style_ax(ax, "Misc Results", "Average lines")

fig.tight_layout()
fig.savefig("overview_results.png", dpi=150, bbox_inches="tight")
print("Saved overview_results.png")
