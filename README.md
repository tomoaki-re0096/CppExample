# CppExample
C++11,14,17の機能を調査([参考URL](https://cpprefjp.github.io/lang.html))
## 環境準備<br>
・Visualstudio 2019 Community を使用<br>
・WindowsSDK 10 を使用→10.0.10240.0以上で動作確認<br>
・ISO C++17 標準 (std:c++17)

## スマートポインター
### [std::shared_ptr（C++11）](https://cpprefjp.github.io/reference/memory/shared_ptr.html)
- どんな機能？<br>
　リソース（newで作成したアドレス）の所有権を共有するクラス型<br>
　（最初に作成したオブジェクトを含めて）所有権を共有したオブジェクトがすべて削除されれば、リソースも解放される。<br>
- 何に使える？<br>
　リソース（ポインタ）をクラス間で共有するが、リソース保持者が削除される前に、リソース共有先の削除が保証されていない場合、アクセス違反が起こりづらい。<br>
### [std::unique_ptr（C++11）](https://cpprefjp.github.io/reference/memory/unique_ptr.html)
- どんな機能？<br>
　リソース（newで作成したアドレス）の所有権は唯一で管理するクラス型<br>
- 何に使える？<br>
　所有権は単一で問題ないオブジェクトの解放忘れを防ぐ。<br>
　リソースへのアクセスはgetterのみなら生ポインタを渡すことも可能だが、それは隠蔽性が落ちる為、要注意。<br>
### [std::make_shared（C++17）](https://cpprefjp.github.io/reference/memory/make_shared.html)
- どんな機能？<br>
　shared_ptr<T>型のオブジェクト生成処理<br>
- 何に使える？<br>
　通常の shared_ptr<T>(new T); では、Tの生成・内部的参照カウンタが別々で確保されるが、  
　make_shared ではTと参照カウンタを1つのブロックで確保されるので効率的。<br>
### [std::make_unique（C++17）](https://cpprefjp.github.io/reference/memory/make_unique.html)
- どんな機能？<br>
　unique_ptr<T>型のオブジェクト生成処理<br>
- 何に使える？<br>
　newで例外が発生した時にnewで確保した時のメモリがリークする…らしい  
　https://ja.stackoverflow.com/questions/24876/make-unique%E3%81%AE%E5%88%A9%E7%82%B9<br>


## ラムダ式
### [ラムダ式（C++11）](https://cpprefjp.github.io/lang/cpp11/lambda_expressions.html)
- どんな機能？<br>
　変数のように関数宣言が、関数ローカル内で可能。<br>
- 何に使える？<br>
　関数内での、関数作成と呼び出しが可能。std::function型として扱うことが出来る。  
　※キャプチャ機能でthisや&を使い、ラムダを宣言しているクラスや、関数内の変数を使うことが出来るが、クラスや変数側の寿命には注意<br>
### [ジェネリックラムダ（C++14）](https://cpprefjp.github.io/lang/cpp14/generic_lambdas.html)
- どんな機能？<br>
　ラムダ式の引数型にautoを使う<br>
- 何に使える？<br>
　関数パラメータをテンプレートのようにしてラムダ式を扱える。  
　※ただし、ラムダ式のautoは、パラメータのテンプレートパラメータには使用できない  
　　テンプレートのままなので、std::functionには代入できない<br>
### [ラムダ式の初期化キャプチャ（C++14）](https://cpprefjp.github.io/lang/cpp14/initialize_capture.html)
- どんな機能？<br>
　任意の式の結果をラムダ式にキャプチャする機能（変数の宣言）<br>
- 何に使える？<br>
　キャプチャリストの箇所で変数宣言が出来る。<br>


## C++11 機能
### [decltype](https://cpprefjp.github.io/lang/cpp11/decltype.html)
- どんな機能？<br>
　変数の型・戻り値型などを、式をもとに型を決定できる。<br>
- 何に使える？<br>
　templateを使用した関数などに対応しやすい。autoと組み合わせると汎用的なコードが書きやすい？<br>
### [範囲For文](https://cpprefjp.github.io/lang/cpp11/range_based_for.html)
- どんな機能？<br>
　配列、コンテナの要素数のループ記述を簡易にできる<br>
- 何に使える？<br>
　配列の全要素のループ。代表的なstd::vector以外にも、自作クラスにも対応可能。<br>
### [一様初期化](https://cpprefjp.github.io/lang/cpp11/uniform_initialization.html),[初期化子リスト](https://cpprefjp.github.io/lang/cpp11/initializer_lists.html)
- どんな機能？<br>
　変数、クラス初期化時に波括弧で初期化することができる（リストの初期化的な）<br>
- 何に使える？<br>
　コンストラクタの引数を波括弧で宣言しreturnで返すことができる。初期化時に()を使うと、関数呼び出しと見間違う可能性を無くせる。<br>
### [右辺値参照・ムーブセマンティクス](https://cpprefjp.github.io/lang/cpp11/rvalue_ref_and_move_semantics.html)
- どんな機能？<br>
　高コストになりがちな代入・コピーを回避するための、ムーブをさせる為のセマンティクスと、従来の（左辺値）参照と分ける為の言語機能<br>
- 何に使える？<br>
　バッファ・マネージャーを有するサイズが大きくなりがちなクラスの、関数・クラスを越えた受け渡しが必要な場合に対応可能<br>
### [overrideとfinal](https://cpprefjp.github.io/lang/cpp11/override_final.html)
- どんな機能？<br>
　明示的なオーバーライド、継承・オーバーライド不可にさせる<br>
- 何に使える？<br>
　クラス設計的に、最終クラスに使う。関数オーバーライドの明示的にすることでの可読性、継承元変更による派生先の更新忘れ防止等<br>

## C++17機能
### [入れ子名前空間の定義](https://cpprefjp.github.io/lang/cpp17/nested_namespace.html)
- どんな機能？<br>
　入れ子になっているnamespaceの宣言等を省略<br>
- 何に使える？<br>
　変数宣言や、namespaceの宣言時に↓のような書き方ができる<br>
　namespace A::B::C::D{ int num;} A::B::C::D::num = 0;<br>
### [if文とswitch文の条件式と初期化を分離](https://cpprefjp.github.io/lang/cpp17/selection_statements_with_initializer.html)
- どんな機能？<br>
　if,switchで条件文内に変数初期化ができる<br>
- 何に使える？<br>
　条件用の変数をif,switch内のみで使用する一時変数的な使い方ができる<br>
### [構造化束縛](https://cpprefjp.github.io/lang/cpp17/structured_bindings.html)
- どんな機能？<br>
　pair・tuple型、map型等の構造体の各要素を取り出す<br>
- 何に使える？<br>
　（mapは特にかもだが）データのバッファと、ハッシュ値的なキーの値を、同時に別変数として取り出すことができる。<br>
### [static_assert のメッセージ省略を許可](https://cpprefjp.github.io/lang/cpp17/extending_static_assert.html)
- どんな機能？<br>
　C++11から実装されたstatic_assertの、第2引数（文字列リテラル）が不要に。<br>
- 何に使える？<br>
　コンパイル時にメッセージが必要にない場合に対応可能<br>
### [std::clamp](https://cpprefjp.github.io/reference/algorithm/clamp.html)
- どんな機能？<br>
　第2,3引数に設定した下限値、上限値に収める。収まっている場合は第1引数の値を返す。<br>
- 何に使える？<br>
　これまでmin、maxを駆使して、下限上限の範囲内収める処理を書いていた箇所を、1行で済ませられる<br>
