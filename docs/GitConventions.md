# Git Conventions

This document describes the Git conventions used in this project. The goal is to keep the development process understandable, traceable and structured by using meaningful branches, small commits and verified changes.


## Branches

Development work is done on feature branches. The `main` branch contains the latest stable project state. Branch names should be descriptive and related to the topic of the change:

* feature/branch-name
* fix/branch-name
* refactor/branch-name
* docs/branch-name
* test/branch-name
* cicd/branch-name


## Naming Conventions

* Directory names are written in lowercase.
* Documentation files use PascalCase.
* Branch names use kebab-case with a type prefix.
* Commit messages are written in English.


## Commits

Commits should be small, understandable and logically related. A commit should contain one coherent change whenever possible. Good commit messages describe what has changed. They do not need to include every technical detail, but they should not be too generic. Commit messages may optionally use simple prefixes:

* feature:   new functionality
* fix:       bug fix
* refactor:  structural change without functional change
* docs:      documentation
* test:      tests
* cicd:      CI/CD changes


## Pull Requests

Changes are merged into the `main` branch using pull requests. A pull request should have a clear technical or functional purpose.


## Tests Before Merging

Before merging, the build and native tests should pass successfully. Hardware-dependent embedded tests are executed locally on the target hardware when the required hardware is available.


## Existing Git History

These conventions apply from the point at which they are introduced. Earlier commits do not need to be changed retroactively.