# Note publisher for Obsidian

# WORK IN PROGRESS


Note publisher is a tool for Obsidian written in C++ that allows you to publish notes from your Obisidan vault to a website.

## How it works:
- It iterates through all the notes in your vault
- It collects all the notes that have a `publish` tag
- It generates either a static website with all the notes that have a `publish` tag
 or a json file with hjson for uploading to a database


### Changelog:
- 0.0.1:
  - reading a markdown file works
  - parsing metadata works
