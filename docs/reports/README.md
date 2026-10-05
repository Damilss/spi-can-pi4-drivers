# Reports

Test logs, bring-up notes, and findings from hands-on sessions with the Pi 4 +
MCP25625 CAN setup. Write a report whenever you test something on real hardware,
especially when the result differs from what the docs or datasheet say. For
example, the board only worked at 16 MHz even though the schematic shows a 20 MHz
crystal.

## Layout

One folder per session, named by date (`YYYY-MM-DD`):

```
reports/
├── README.md              <- you are here
├── README_TEMPLATE.md     <- copy this for new reports
└── 2026-09-23/
    └── pi_config_9_23.md
```

Put any supporting files (candump logs, screenshots, scope captures) in the same
dated folder as the report.

## Writing a new report

1. Create a folder for the date: `mkdir docs/reports/YYYY-MM-DD`
2. Copy the template: `cp docs/reports/README_TEMPLATE.md docs/reports/YYYY-MM-DD/<short-topic>.md`
3. Fill in each section. If a section doesn't apply, write "N/A" instead of
   deleting it.
4. Add the report to the index below.

## Guidelines

- **Record what actually happened**, not what was supposed to happen. Failed
  tests are worth just as much as passing ones.
- **Include the exact commands** you ran and the output (or a trimmed version).
- **Note the hardware/software state**: which Pi, which board, overlay settings,
  bitrate, and the commit hash you tested.
- **If a finding changes how setup should be done**, update the relevant guide in
  `docs/` (e.g. `can0-setup.md`) and link back to the report.

## Index

| Date       | Report                                                  | Summary                                       |
|------------|---------------------------------------------------------|-----------------------------------------------|
| 2026-09-23 | [pi_config_9_23.md](2026-09-23/pi_config_9_23.md)        | CAN overlay config + loopback test on the Pi (SUCCESSFUL)  |
