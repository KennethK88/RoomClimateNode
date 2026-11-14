# Git Conventions

This document describes the Git conventions used in the RoomClimateNode project. The goal is to keep development understandable, traceable, and
structured through meaningful branches, focused commits, and verified changes.


## Branches

Development work is performed on dedicated branches. The `main` branch represents the latest stable project state. Branch names use a descriptive kebab-case identifier with a type prefix.

Supported branch prefixes:

- `feature/` - New functionality
- `fix/` - Bug fixes
- `refactor/` - Code restructuring
- `docs/` - Documentation changes
- `test/` - Test-related changes
- `ci/` - CI/CD configuration and workflows
- `chore/` - Maintenance and infrastructure tasks

Examples:

- `feature/add-battery-monitoring`
- `fix/handle-sensor-errors`
- `refactor/simplify-controller`
- `docs/update-architecture-documentation`
- `ci/restore-github-actions`


## Naming Conventions

- Directory names use lowercase.
- Documentation files use PascalCase, except standard files such as README.md.
- Branch names use kebab-case with a type prefix.
- Commit messages are written in English.


## Commits

Commits should be small, understandable, and logically related. Each commit should represent one coherent change whenever possible. Commit messages follow the Conventional Commits naming convention.

Format:

`<type>: <description>`

Supported commit types:

- `feat:` - New functionality
- `fix:` - Bug fixes
- `refactor:` - Code restructuring without functional changes
- `docs:` - Documentation changes
- `test:` - Adding or modifying tests
- `chore:` - Maintenance, build configuration, and infrastructure
- `style:` - Formatting and style changes without functional impact
- `ci:` - CI/CD workflow changes

Examples:

- `feat: add battery level reporting`
- `fix: handle invalid sensor measurements`
- `refactor: simplify controller dependencies`
- `docs: update UML architecture diagrams`
- `test: add sensor validation tests`
- `chore: update PlatformIO configuration`
- `ci: fix GitHub Actions workflow`

Commit descriptions should be concise and describe the actual change.


## Pull Requests

Changes are integrated into the `main` branch using pull requests. Each pull request should have a clear technical or functional purpose. The changes should be reviewed before merging.


## Tests Before Merging

Before merging, the relevant builds and available automated tests should pass successfully. Hardware-dependent embedded tests are executed locally on the target hardware when the required hardware is available. Changes should not knowingly introduce build failures or test regressions.


## Existing Git History

These conventions apply from the point at which they are introduced. Earlier commits do not need to be modified retroactively.