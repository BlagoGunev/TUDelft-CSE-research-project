import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import numpy as np

# =============================================================================
# RAW DATA — edit these counts to update all plots
# =============================================================================

simple_key = "Simple"
cot_key = "Chain-of-Thought"

DATA = {
    # prompt extraction: total inputs → correctly extracted
    simple_key: {
        "pe_inputs":   208,   # total input files
        "pe_correct":  196,   # successfully extracted

        "co_inputs":   196,   # = pe_correct; files fed to compiler
        "co_compiled": 122,   # successfully compiled

        "bm_inputs":   100,   # files fed to benchmark (tested)
        "bm_correct":  39,   # passed benchmark

        # runtime = compiled but not tested
        # compile_error = not compiled (co_inputs - co_compiled)
        # functional_error = tested but wrong (bm_inputs - bm_correct)
    },
    cot_key: {
        "pe_inputs":   208,
        "pe_correct":  122,

        "co_inputs":   122,
        "co_compiled": 78,

        "bm_inputs":   63,
        "bm_correct":  27,
    },
}

# =============================================================================
# STYLE
# =============================================================================

C_SIMPLE = "#4C9BE8"
C_PLAN   = "#E8834C"

STACK_COLORS = {
    "Successful Translation":  "#4CAF50",
    "Functional Error":        "#F5C842",
    "Missing Tests":           "#4C9BE8",
    "Compilation Error":       "#E8474C",
    "Prompt Extraction Error": "#9B59B6",
}

BAR_W = 0.32

# =============================================================================
# DERIVED METRICS
# =============================================================================

def pct(k, n):
    return k / n * 100

def wilson_ci(k, n, z=1.96):
    """95 % Wilson score CI; returns (lower_err, upper_err) in percentage points."""
    p = k / n
    denom  = 1 + z**2 / n
    centre = (p + z**2 / (2 * n)) / denom
    half   = z * np.sqrt(p * (1 - p) / n + z**2 / (4 * n**2)) / denom
    lo = max(0.0, centre - half) * 100
    hi = min(1.0, centre + half) * 100
    p_pct = p * 100
    return p_pct - lo, hi - p_pct

variants = list(DATA.keys())   # ["simple", "plan"]

# Percentages for panel 1
pe_pct = {v: pct(DATA[v]["pe_correct"], DATA[v]["pe_inputs"]) for v in variants}
co_pct = {v: pct(DATA[v]["co_compiled"], DATA[v]["co_inputs"]) for v in variants}
bm_pct = {v: pct(DATA[v]["bm_correct"], DATA[v]["bm_inputs"]) for v in variants}

# Wilson CIs — n is the input size for each step
pe_err = {v: wilson_ci(DATA[v]["pe_correct"], DATA[v]["pe_inputs"]) for v in variants}
co_err = {v: wilson_ci(DATA[v]["co_compiled"], DATA[v]["co_inputs"]) for v in variants}
bm_err = {v: wilson_ci(DATA[v]["bm_correct"], DATA[v]["bm_inputs"]) for v in variants}

simple_vals = [pe_pct[simple_key], co_pct[simple_key], bm_pct[simple_key]]
plan_vals   = [pe_pct[cot_key],   co_pct[cot_key],   bm_pct[cot_key]]

errs_simple = np.array([[pe_err[simple_key][0], co_err[simple_key][0], bm_err[simple_key][0]],
                         [pe_err[simple_key][1], co_err[simple_key][1], bm_err[simple_key][1]]])
errs_plan   = np.array([[pe_err[cot_key][0],   co_err[cot_key][0],   bm_err[cot_key][0]],
                         [pe_err[cot_key][1],   co_err[cot_key][1],   bm_err[cot_key][1]]])

# Stacked breakdown for panel 2 — all as % of pe_inputs
def make_stack(v):
    d   = DATA[v]
    n   = d["pe_inputs"]
    return {
        "Successful Translation":  pct(d["bm_correct"],                         n),
        "Functional Error":        pct(d["bm_inputs"]  - d["bm_correct"],        n),
        "Missing Tests":           pct(d["co_compiled"] - d["bm_inputs"],         n),
        "Compilation Error":       pct(d["co_inputs"]  - d["co_compiled"],        n),
        "Prompt Extraction Error": pct(d["pe_inputs"]  - d["pe_correct"],         n),
    }

stacks = [make_stack(v) for v in variants]

# =============================================================================
# PLOT
# =============================================================================

# fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(7, 9))
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(13, 5))
# fig.suptitle("Results Summary", fontsize=14, fontweight="bold", y=0.98)

# ── Panel 1: metric percentages with CI ──────────────────────────────────────
metrics = ["Prompt\nExtraction", "Compilation", "Behaviour"]
xs = np.arange(len(metrics))

b1 = ax1.bar(xs - BAR_W/2, simple_vals, BAR_W, color=C_SIMPLE, label=simple_key,
             edgecolor="black", linewidth=0.8, zorder=3)
b2 = ax1.bar(xs + BAR_W/2, plan_vals,   BAR_W, color=C_PLAN,   label=cot_key,
             edgecolor="black", linewidth=0.8, zorder=3)

ax1.errorbar(xs - BAR_W/2, simple_vals, yerr=errs_simple,
             fmt="none", ecolor="black", elinewidth=1.2, capsize=4, capthick=1.2, zorder=4)
ax1.errorbar(xs + BAR_W/2, plan_vals,   yerr=errs_plan,
             fmt="none", ecolor="black", elinewidth=1.2, capsize=4, capthick=1.2, zorder=4)

# for bar in list(b1) + list(b2):
#     h = bar.get_height()
#     ax1.text(bar.get_x() + bar.get_width()/2, h + 0.8,
#              f"{h:.1f}%", ha="center", va="bottom", fontsize=8.5)

ax1.set_xticks(xs)
ax1.set_xticklabels(metrics, fontsize=10)
ax1.set_ylabel("Percentage (%)", fontsize=10)
ax1.set_ylim(0, 110)
# ax1.set_title("Metric Success Rates", fontsize=11, fontweight="bold")
ax1.yaxis.grid(True, linestyle="--", alpha=0.45, zorder=0)
ax1.spines[["top", "right"]].set_visible(False)
ax1.set_axisbelow(True)
ax1.legend(fontsize=9)

# ── Panel 2: stacked breakdown ───────────────────────────────────────────────
bar_positions = list(range(len(variants)))
bottoms = [0.0] * len(variants)

MIN_LABEL_PCT = 1.5   # skip label if segment too thin

# simple bar (pos 0) → label on left; plan bar (pos 1) → label on right
label_sides = {0: ("left",  -0.43),
               1: ("left",  -0.43)}

for cat in STACK_COLORS:
    vals = [stacks[i][cat] for i in range(len(variants))]
    ax2.bar(bar_positions, vals, width=0.52,
            bottom=bottoms,
            color=STACK_COLORS[cat],
            edgecolor="black", linewidth=0.8,
            label=cat, zorder=3)
    for i, (pos, val, bot) in enumerate(zip(bar_positions, vals, bottoms)):
        if val < MIN_LABEL_PCT:
            continue
        ha, x_off = label_sides[i]
        ax2.text(pos + x_off, bot + val / 2,
                 f"{val:.1f}%", ha=ha, va="center", fontsize=7.5, zorder=5)
    bottoms = [bottoms[i] + vals[i] for i in range(len(variants))]

ax2.set_xticks(bar_positions)
ax2.set_xticklabels(variants, fontsize=10)
ax2.set_ylabel("Translations (%)", fontsize=10)
ax2.set_ylim(0, 110)
# ax2.set_title("Translation Breakdown", fontsize=11, fontweight="bold")
ax2.yaxis.grid(True, linestyle="--", alpha=0.45, zorder=0)
ax2.spines[["top", "right"]].set_visible(False)
ax2.set_axisbelow(True)
ax2.set_xlim(-0.6, 2.2)

legend_patches = [mpatches.Patch(facecolor=v, edgecolor="black", linewidth=0.8, label=k)
                  for k, v in STACK_COLORS.items()]
ax2.legend(handles=legend_patches, fontsize=8.5, title="Legend",
           title_fontsize=9, loc="upper right",
           framealpha=0.9, edgecolor="#cccccc")

fig.tight_layout()
fig.savefig("combined_results.png", dpi=150, bbox_inches="tight")
print("Saved combined_results.png")
