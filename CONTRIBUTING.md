# Contributing

Thanks for helping out with `spi-can-pi4-drivers`! Contributions from Cal Poly
FSAE firmware new members are welcome.

## Getting Started

1. Clone the repo.
2. Read the [README](../README.md) for the project overview.
3. Set up your hardware using [can0-setup.md](./can0-setup.md) and
   [spi-setup.md](./spi-setup.md).

## Committing to main

- As a good rule of thumb please don't do commit directly to main, especially for large commits

## Branching

- Branch off `main`.
- Use short, descriptive branch names, e.g. `docs-contributing`, `fix-enable-can`.

## Commit Messages

It would be smart to use [Conventional Commits](https://www.conventionalcommits.org/):

```
type(scope): short summary
```

Common types: `feat`, `fix`, `docs`, `style`, `chore`

Examples:

```
fix(enable-can): fix premature non-zero exit in both enable-CAN scripts
docs(readme): enhance readme and remove irrelevant notes
```

## Pull Requests

- Open PRs against `main`.
- **MERGE** only, no squash or rebase
- Describe **what** changed and **why**.
- Note what hardware you tested on (e.g. Pi 4 + MCP25625 click).
- Get at least one review from another member. If no member is available at least review with AI

## Project Layout

- `docs/` - setup guides, datasheets, and reference material
- `scripts/` - shell scripts, grouped into subfolders by purpose
- `src/` - C/C++ source

## Questions

Feel free to at in a discussion or thread in the Github or on Slack.

