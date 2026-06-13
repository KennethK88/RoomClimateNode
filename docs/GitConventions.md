# Git-Konventionen

Diese Datei beschreibt die Git-Konventionen für das Projekt. Ziel ist ein nachvollziehbarer, sauberer Entwicklungsprozess mit kleinen Änderungen, verständlichen Commits und überprüfbaren Zwischenständen.

## Branches

Entwicklungsarbeiten erfolgen grundsätzlich auf Feature-Branches. Der `main`-Branch enthält den jeweils stabilen Stand des Projekts.

Branch-Namen werden sprechend und themenbezogen vergeben.

Beispiele:

```text
feature/mqtt-publishing
feature/sht31-integration
feature/home-assistant-integration
refactor/library-structure
docs/update-doxygen
test/sht31-embedded-tests
ci/update-platformio-workflow
```

## Commits

Commits sollen klein, nachvollziehbar und fachlich zusammenhängend sein. Ein Commit enthält möglichst genau eine abgeschlossene Änderung.

Gute Commit-Nachrichten beschreiben, was geändert wurde. Sie müssen nicht jedes technische Detail enthalten, sollen aber auch nicht zu allgemein sein.

Beispiele:

```text
Add MQTT publishing for room climate measurements
Refactor library structure into connectivity and drivers
Update Doxygen documentation
Fix SHT31 humidity validation
Add native tests for state machine
```

## Commit-Typen

Optional können Commit-Nachrichten mit einfachen Präfixen versehen werden. Dadurch wird schneller erkennbar, welche Art von Änderung ein Commit enthält.

```text
feat:      neue Funktion
fix:       Fehlerbehebung
refactor:  strukturelle Änderung ohne Funktionsänderung
docs:      Dokumentation
test:      Tests
ci:        Änderungen an CI/CD
chore:     sonstige Wartungsarbeiten
```

Beispiele:

```text
feat: add MQTT measurement publisher
fix: handle invalid humidity values
refactor: split connectivity and driver components
docs: update project overview
test: add native tests for validation logic
ci: update PlatformIO workflow
```

## Pull Requests

Änderungen werden über Pull Requests in den `main`-Branch übernommen. Vor dem Merge sollen Build und Tests erfolgreich sein.

Ein Pull Request sollte einen klaren fachlichen oder technischen Zweck haben, z. B.:

```text
Add MQTT support
Refactor library structure
Update project documentation
Add SHT31 sensor integration
```

## Tests vor dem Merge

Vor dem Merge sollten mindestens folgende Prüfungen erfolgreich sein:

```bash
pio run
pio test -e native
```

Hardwareabhängige Embedded Tests werden lokal auf der Zielhardware ausgeführt, sofern die benötigte Hardware verfügbar ist.

## Umgang mit bestehender Historie

Diese Konventionen gelten ab dem Zeitpunkt ihrer Einführung. Frühere Commits müssen nicht nachträglich angepasst werden.

Die bisherige Git-Historie spiegelt den Entwicklungs- und Lernprozess des Projekts wider. Wichtig ist, dass zukünftige Änderungen zunehmend nach diesen Konventionen umgesetzt werden.



\## Naming Conventions



\- Directory names are written in lowercase.

\- Documentation files use PascalCase.

\- Branch names use kebab-case with a type prefix.

\- Commit messages are written in English.

