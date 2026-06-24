import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
from matplotlib.ticker import FormatStrFormatter
import numpy as np

simple_key = "Simple"
cot_key = "Chain-of-Thought"

# ── shared style ──────────────────────────────────────────────────────────────
COLORS = {simple_key: "#4C9BE8", cot_key: "#E8834C"}
BAR_W  = 0.35
FIG_W, FIG_H = 7, 4.5

def style_ax(ax, title, ylabel):
    # ax.set_title(title, fontsize=13, fontweight="bold", pad=10)
    ax.set_ylabel(ylabel, fontsize=10)
    ax.spines[["top", "right"]].set_visible(False)
    ax.yaxis.grid(True, linestyle="--", alpha=0.5)
    ax.set_axisbelow(True)
    legend = [mpatches.Patch(facecolor=COLORS[simple_key], edgecolor="black", linewidth=0.8, label=simple_key),
              mpatches.Patch(facecolor=COLORS[cot_key],   edgecolor="black", linewidth=0.8, label=cot_key)]
    ax.legend(handles=legend, fontsize=9)

def plot_bars(ax, xs, simple_vals, plan_vals):
    b1 = ax.bar(xs - BAR_W/2, simple_vals, BAR_W,
                color=COLORS[simple_key], edgecolor="black", linewidth=0.8, zorder=3)
    b2 = ax.bar(xs + BAR_W/2, plan_vals,   BAR_W,
                color=COLORS[cot_key],   edgecolor="black", linewidth=0.8, zorder=3)
    # for bars in (b1, b2):
    #     for bar in bars:
    #         h = bar.get_height()
    #         ax.text(bar.get_x() + bar.get_width() / 2, h + ax.get_ylim()[1] * 0.01,
    #                 f"{h:g}", ha="center", va="bottom", fontsize=9)
    return b1, b2


# ── 1. compile_results ────────────────────────────────────────────────────────
# compile_data = {
#     simple_key: {"inputs": 73, "compiled": 51, "not compiled": 22},
#     cot_key:   {"inputs": 46, "compiled": 31, "not compiled": 15},
# }

compile_data = {
    simple_key: {"inputs": 196, "compiled": 122, "not compiled": 74},
    cot_key:   {"inputs": 122, "compiled": 78, "not compiled": 44},
}
labels_c = ["inputs", "compiled", "not compiled"]
xs = np.arange(len(labels_c))

fig, ax = plt.subplots(figsize=(FIG_W, FIG_H))
plot_bars(ax, xs,
          [compile_data[simple_key][l] for l in labels_c],
          [compile_data[cot_key][l]   for l in labels_c])
ax.set_xticks(xs); ax.set_xticklabels(labels_c)
style_ax(ax, "Compilation Results", "Count")
fig.tight_layout()
fig.savefig("compile_results.png", dpi=150)
print("Saved compile_results.png")


# ── 2. benchmark_results ──────────────────────────────────────────────────────
# bench_data = {
#     simple_key: {"tested": 40, "correct": 18, "incorrect": 22},
#     cot_key:   {"tested": 22, "correct": 11, "incorrect": 11},
# }

bench_data = {
    simple_key: {"tested": 100, "correct": 39, "incorrect": 61},
    cot_key:   {"tested": 63, "correct": 27, "incorrect": 36},
}
labels_b = ["tested", "correct", "incorrect"]
xs = np.arange(len(labels_b))

fig, ax = plt.subplots(figsize=(FIG_W, FIG_H))
plot_bars(ax, xs,
          [bench_data[simple_key][l] for l in labels_b],
          [bench_data[cot_key][l]   for l in labels_b])
ax.set_xticks(xs); ax.set_xticklabels(labels_b)
style_ax(ax, "Behaviour Results", "Count")
fig.tight_layout()
fig.savefig("benchmark_results.png", dpi=150)
print("Saved benchmark_results.png")


# ── 3. misc_results ───────────────────────────────────────────────────────────
# misc_data = {
#     simple_key: {"avg lines of code": 74.82, "avg lines of comments": 33.97},
#     cot_key:   {"avg lines of code": 84.63, "avg lines of comments": 16.33},
# }

misc_data = {
    simple_key: {"avg lines of code": 80.38, "avg lines of comments": 56.10},
    cot_key:   {"avg lines of code": 87.15, "avg lines of comments": 17.59},
}
labels_m = ["avg lines of code", "avg lines of comments"]
xs = np.arange(len(labels_m))

fig, ax = plt.subplots(figsize=(FIG_W, FIG_H))
plot_bars(ax, xs,
          [misc_data[simple_key][l] for l in labels_m],
          [misc_data[cot_key][l]   for l in labels_m])
ax.set_xticks(xs); ax.set_xticklabels(labels_m)
style_ax(ax, "Code Stat Results", "Average lines")
fig.tight_layout()
fig.savefig("misc_results.png", dpi=150)
print("Saved misc_results.png")


# ── 4. prompt_extraction_results ──────────────────────────────────────────────
# prompt_data = {
#     simple_key: {"input files": 78, "correct": 73, "incorrect": 5},
#     cot_key:   {"input files": 78, "correct": 46, "incorrect": 32},
# }

prompt_data = {
    simple_key: {"input files": 208, "correct": 196, "incorrect": 12},
    cot_key:   {"input files": 208, "correct": 122, "incorrect": 86},
}
labels_p = ["input files", "correct", "incorrect"]
xs = np.arange(len(labels_p))

fig, ax = plt.subplots(figsize=(FIG_W, FIG_H))
plot_bars(ax, xs,
          [prompt_data[simple_key][l] for l in labels_p],
          [prompt_data[cot_key][l]   for l in labels_p])
ax.set_xticks(xs); ax.set_xticklabels(labels_p)
style_ax(ax, "Prompt Extraction Results", "Count")
fig.tight_layout()
fig.savefig("prompt_extraction_results.png", dpi=150)
print("Saved prompt_extraction_results.png")
