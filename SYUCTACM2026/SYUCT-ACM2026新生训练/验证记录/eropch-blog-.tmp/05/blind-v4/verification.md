# Blind review (v4) — verification record

- Prompt: frozen public statement + constraints + samples + judge semantics only (`blind-v4/prompt.md`).
  Verified prompt contains no workspace paths, no generator/solution/validator/checker names.
- Model actually used: `wb2api/deepseek-v4.1-flash`
  (confirmed from session wire log: `llm.request` model `deepseek-v4.1-flash`, `usage.record` model `wb2api/deepseek-v4.1-flash`).
- Response: `blind-v4/response.md` (8 sections: restatement, algorithm, proof, complexity, edge cases, 3-layer errors, assumptions, full C++17).
- Blind conclusion: no substantive ambiguity or hidden traps in the frozen statement; x=y, no-occurrence, first/last position, single-case, exact-one-line output are all explicitly pinned down.
- Cross-check: blind C++17 implementation compiled and diff-tested against main on 200 randomized inputs
  (lengths 1..100000, alphabets 1..26, x=y ~20%) -> 0 mismatches.
- solution2 is an independent implementation informed by the blind conclusion (26-way map + range-for + fwrite),
  not a copy of the blind code, so main/solution2 remain two distinct code paths.
