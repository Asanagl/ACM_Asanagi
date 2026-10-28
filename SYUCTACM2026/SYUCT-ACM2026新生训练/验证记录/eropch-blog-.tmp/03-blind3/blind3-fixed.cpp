  #include <iostream>
  #include <string>

  int main() {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);

      std::string s;
      if (!(std::cin >> s)) {
          std::cout << "0 0 0 0 0\n";
          return 0;
      }

      long long cnt[5] = {0, 0, 0, 0, 0};
      for (char ch : s) {
          char c = static_cast<char>(static_cast<unsigned char>(ch) | 0x20u);
          switch (c) {
              case 'a': ++cnt[0]; break;
              case 'e': ++cnt[1]; break;
              case 'i': ++cnt[2]; break;
              case 'o': ++cnt[3]; break;
              case 'u': ++cnt[4]; break;
              default: break;
          }
      }

      for (int j = 0; j < 5; ++j) {
          if (j) std::cout << ' ';
          std::cout << cnt[j];
      }
      std::cout << '\n';
      return 0;
  }
  