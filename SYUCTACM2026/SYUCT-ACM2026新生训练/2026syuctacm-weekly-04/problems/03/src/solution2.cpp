#include <cstddef>
#include <cstdio>

namespace {
constexpr std::size_t kBufSize = 1u << 16;
char g_buf[kBufSize];
}  // namespace

int main() {
    int cnt[5] = {0, 0, 0, 0, 0};

    std::size_t got;
    while ((got = std::fread(g_buf, 1, kBufSize, stdin)) > 0) {
        for (std::size_t k = 0; k < got; ++k) {
            char c = g_buf[k];
            if (c >= 'A' && c <= 'Z') {
                c = static_cast<char>(c - 'A' + 'a');
            }
            switch (c) {
                case 'a': ++cnt[0]; break;
                case 'e': ++cnt[1]; break;
                case 'i': ++cnt[2]; break;
                case 'o': ++cnt[3]; break;
                case 'u': ++cnt[4]; break;
                default: break;
            }
        }
    }

    std::printf("%d %d %d %d %d\n", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]);
    return 0;
}
