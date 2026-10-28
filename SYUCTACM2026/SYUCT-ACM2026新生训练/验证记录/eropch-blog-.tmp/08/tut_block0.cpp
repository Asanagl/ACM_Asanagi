for (int i = 0; i + m <= n; ++i) {
    if (s.compare(i, m, t) == 0) { cout << i << '\n'; return 0; }
}
cout << -1 << '\n';
