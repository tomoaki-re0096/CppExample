# CppExample
C++11,14,17の機能を調査([参考URL](https://cpprefjp.github.io/lang.html))
## 環境準備<br>
・Visualstudio 2017 Community を使用<br>
・WindowsSDK 10 を使用→10.0.10240.0以上で動作確認<br>
・@todo:https://docs.microsoft.com/ja-jp/cpp/build/reference/std-specify-language-standard-version?view=vs-2019

## スマートポインター
### [std::shared_ptr（C++11）]()
どんな機能？<br>
　<br>
何に使える？<br>
　<br>
### [std::unique_ptr（C++11）]()
どんな機能？<br>
　<br>
何に使える？<br>
　<br>
### [std::make_shared（C++17）]()
どんな機能？<br>
　<br>
何に使える？<br>
　<br>
### [std::make_unique（C++17）]()
どんな機能？<br>
　<br>
何に使える？<br>
　<br>


## ラムダ式
### [ラムダ式（C++11）](https://cpprefjp.github.io/lang/cpp11/lambda_expressions.html)
どんな機能？<br>
　<br>
何に使える？<br>
　<br>
### [ジェネリックラムダ（C++14）](https://cpprefjp.github.io/lang/cpp14/generic_lambdas.html)
どんな機能？<br>
　<br>
何に使える？<br>
　<br>
### [ラムダ式の初期化キャプチャ（C++14）](https://cpprefjp.github.io/lang/cpp14/initialize_capture.html)
どんな機能？<br>
　<br>
何に使える？<br>
　<br>


## C++11 機能
### [decltype](https://cpprefjp.github.io/lang/cpp11/decltype.html)
どんな機能？<br>
　変数の型・戻り値型などを、式をもとに型を決定できる。<br>
何に使える？<br>
　templateを使用した関数などに対応しやすい。autoと組み合わせると汎用的なコードが書きやすい？<br>
### [範囲For文](https://cpprefjp.github.io/lang/cpp11/range_based_for.html)
どんな機能？<br>
　配列、コンテナの要素数のループ記述を簡易にできる<br>
何に使える？<br>
　配列の全要素のループ。代表的なstd::vector以外にも、自作クラスにも対応可能。<br>
### [一様初期化](https://cpprefjp.github.io/lang/cpp11/uniform_initialization.html),[初期化子リスト](https://cpprefjp.github.io/lang/cpp11/initializer_lists.html)
どんな機能？<br>
　変数、クラス初期化時に波括弧で初期化することができる（リストの初期化的な）<br>
何に使える？<br>
　コンストラクタの引数を波括弧で宣言しreturnで返すことができる。初期化時に()を使うと、関数呼び出しと見間違う可能性を無くせる。<br>
### [右辺値参照・ムーブセマンティクス](https://cpprefjp.github.io/lang/cpp11/rvalue_ref_and_move_semantics.html)
どんな機能？<br>
　高コストになりがちな代入・コピーを回避するための、ムーブをさせる為のセマンティクスと、従来の（左辺値）参照と分ける為の言語機能<br>
何に使える？<br>
　バッファ・マネージャーを有するサイズが大きくなりがちなクラスの、関数・クラスを越えた受け渡しが必要な場合に対応可能<br>
### [overrideとfinal](https://cpprefjp.github.io/lang/cpp11/override_final.html)
どんな機能？<br>
　明示的なオーバーライド、継承・オーバーライド不可にさせる<br>
何に使える？<br>
　クラス設計的に、最終クラスに使う。関数オーバーライドの明示的にすることでの可読性、継承元変更による派生先の更新忘れ防止等<br>

## C++17機能
### [入れ子名前空間の定義](https://cpprefjp.github.io/lang/cpp17/nested_namespace.html)
どんな機能？<br>
　入れ子になっているnamespaceの宣言等を省略<br>
何に使える？<br>
　変数宣言や、namespaceの宣言時に↓のような書き方ができる<br>
　namespace A::B::C::D{ int num;} A::B::C::D::num = 0;<br>
### [if文とswitch文の条件式と初期化を分離](https://cpprefjp.github.io/lang/cpp17/selection_statements_with_initializer.html)
どんな機能？<br>
　if,switchで条件文内に変数初期化ができる<br>
何に使える？<br>
　条件用の変数をif,switch内のみで使用する一時変数的な使い方ができる<br>
### [構造化束縛](https://cpprefjp.github.io/lang/cpp17/structured_bindings.html)
どんな機能？<br>
　pair・tuple型、map型等の構造体の各要素を取り出す<br>
何に使える？<br>
　（mapは特にかもだが）データのバッファと、ハッシュ値的なキーの値を、同時に別変数として取り出すことができる。<br>
### [static_assert のメッセージ省略を許可]()
どんな機能？<br>
　<br>
何に使える？<br>
　<br>
### [std::clamp]()
どんな機能？<br>
　<br>
何に使える？<br>
　<br>
