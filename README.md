# The Little Book of C

This is _The Little Book of C_ 

## Formats

- [Download PDF](releases/book.pdf) - print-ready
- [Download EPUB](releases/book.epub) - e-reader friendly
- [View LaTeX](releases/book.tex) - `.tex` source
- [Read on GitHub Pages](https://little-book-of.github.io/c/) - online website

## Build it yourself (Quarto)

We use [Quarto](https://quarto.org/docs/get-started/) to generate all outputs.

Preview locally:

```bash
quarto preview
```

Render outputs:

```bash
# All configured formats
quarto render

# Individual formats
quarto render --to html     # site into docs/
quarto render --to pdf      # docs/book.pdf
quarto render --to epub     # docs/book.epub
quarto render --to latex    # docs/book-latex/book.tex
```

## Contributing

We welcome contributions: fixing typos, clarifying sections, adding diagrams, or
improving examples.

## Citation

Nguyen, Duc-Tam (2025). _The Little Book of Maths_

```
@book{Nguyen2025TLBoC,
  author = {Duc-Tam Nguyen},
  title  = {The Little Book of Maths},
  year   = {2025},
  url    = {https://github.com/little-book-of/c}
}
```

## License

Licensed under **CC BY-NC-SA 4.0**. See [LICENSE](LICENSE) for details.
