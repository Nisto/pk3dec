# pk3dec

Decodes audio used in some PS2 games developed by tri-Ace. Exact codec name is not yet known, but the extensions `.PK3` and `.020` have been used informally. Additionally, names of relevant functions contain references to `Sac`.

### Known supported games
- Star Ocean: Till the End of Time

### TODO
- Fix off-by-one mismatches against PCSX2 (comparing directly to VU1 memory)
- Decompile VU1-style code to plain C
- Handle loop information
- Implement StMakeFinalOut?
- Implement StFlushWriteBuffer?
