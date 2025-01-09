# Projet_QDP : Simulation de Robot

Ce projet est une simulation de robot se déplaçant sur un terrain, avec un système d'observateurs pour notifier les changements d'état.

## Table des matières

- [Description](#description)
- [Structure du Projet](#structure-du-projet)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Contribution](#contribution)
- [Licence](#licence)

## Description

Ce projet utilise une architecture orientée objet pour simuler un robot se déplaçant sur un terrain composé de cases. Le robot peut avancer, tourner à droite ou à gauche, et notifier des observateurs de ses mouvements. Les observateurs peuvent être de différents types, comme des observateurs de console.

## Structure du Projet

Le projet est structuré en plusieurs classes principales :

- **OBSERVATEUR (abstrait)** : Classe abstraite définissant la méthode `notifier`.
- **OBSERVATEUR Console** : Classe dérivée de `OBSERVATEUR` implémentant la méthode `notifier` pour afficher des notifications dans la console.
- **ROBOT** : Classe représentant le robot, avec des méthodes pour se déplacer et notifier les observateurs.
- **TERRAIN** : Classe représentant le terrain, composé de cases.
- **CASE** : Classe représentant une case individuelle du terrain.

### Diagramme de Classe

```
OBSERVATEUR (abstrait)
|-- méthode : notifier
|
|-- classe dérivée
|
OBSERVATEUR Console
|-- méthode : notifier

ROBOT
|-- variables : x, y, liste d'observateur, pointeur sur le Terrain
|-- méthodes : avance, tourner à droite, tourner à gauche, retourne x, retourne y, notifier observateur, ajouter observateur
|
|-- Se déplace sur
|
TERRAIN
|-- variables : tableau 2D de cases, longueur, largeur
|-- méthodes : sauvegarder, charger, position valide
|
|-- est constitué de
|
CASE
|-- variables : type, x, y
```

## Installation

Pour installer le projet, suivez ces étapes :

1. Clonez le dépôt :
   ```sh
   git clone https://github.com/votre-utilisateur/votre-depot.git
   ```
2. Accédez au répertoire du projet :
   ```sh
   cd votre-depot
   ```
3. Installez les dépendances (si nécessaire) :
   ```sh
   pip install -r requirements.txt
   ```

## Utilisation

Pour utiliser le projet, vous pouvez exécuter le fichier principal `main.cpp` :

Ce fichier initialisera le terrain, placera le robot, et permettra au robot de se déplacer tout en notifiant les observateurs.