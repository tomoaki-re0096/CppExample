# CppExample
C++11,14,17の機能を調査([参考URL](https://cpprefjp.github.io/lang.html))
## 環境準備<br>
・Visualstudio 2017 Community を使用<br>
・WindowsSDK 10 を使用<br>
## C++11 機能
### [decltype](https://cpprefjp.github.io/lang/cpp11/decltype.html)
どんな機能？<br>
　変数の型・戻り値型などを、式をもとに型を決定できる。<br>
何に使える？<br>
　templateを使用した関数などに対応しやすい<br>
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
