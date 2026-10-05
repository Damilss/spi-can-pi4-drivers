# <Report Title> — YYYY-MM-DD

**Author(s):** <names>
**Status:** Success / Fail / Partial / Inconclusive
**Related docs:** <e.g. `docs/can0-setup.md`, `docs/can0-testing.md`>

## Goal

<One or two sentences on what you were trying to test or find out. For example,
"Verify can0 sends and receives frames at 1 Mbit/s in loopback mode.">

## Setup

<Any setup instructions or relevant information for the session>

## Procedure

<basic procedure instructions on what went down, steps taken, relevant commands, etc>

## Expected Results

<What should happen if everything works.>.

## Actual Results

<What actually happened. Paste relevant output.>

```
<paste candump / dmesg / program output here>
```

<possible useful diagnostics:>

```
ip -details -statistics link show can0
dmesg | grep -i -E "mcp|can|spi"
```

## Issues / Observations

<Anything unexpected, such as errors, bus-off states, dropped frames, or
differences from the datasheet or schematic. Note workarounds too.>

- <issue> → <workaround or "unresolved">

## Conclusion

<Short summary. Did it pass? What did we learn?>

## Next Steps

- [ ] <follow-up test or fix>
- [ ] <doc to update based on findings>
- [ ] document issues in issues tab on the repo


## Attachments

<Links to logs, screenshots, or scope captures in this folder.>

- `./candump-YYYY-MM-DD.log`
