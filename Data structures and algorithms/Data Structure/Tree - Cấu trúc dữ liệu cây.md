# Cấu trúc dữ liệu cây

## Contents

* [1 Cấu trúc dữ liệu cây](#1-Cấu-trúc-dữ-liệu-cây)
* [2 Duyệt cây](#2-Duyệt-cây)
* [3 Cây tìm kiếm nhị phân](#3-Cây-tìm-kiếm-nhị-phân)
* [4 Cây AVL](#4-Cây-AVL)
* [5 Cây SPLAY](#5-Cây-SPLAY)
* [6 Cây khung - Spanning Tree](#6-Cây-khung)
* [7 Cấu trúc dữ liệu Heap](#7-Heap)

## 1 Cấu trúc dữ liệu cây

### 1.0 Cấu trúc dữ liệu cây

Cấu trúc dữ liệu cây biểu diễn các nút (node) được kết nối bởi các cạnh. Chúng ta sẽ tìm hiểu về Cây nhị phân (Binary Tree) và Cây tìm kiếm nhị phân (Binary Search Tree) trong phần này.

Cây nhị phân là một cấu trúc dữ liệu đặc biệt được sử dụng cho mục đích lưu trữ dữ liệu. Một cây nhị phân có một điều kiện đặc biệt là mỗi nút có thể có tối đa hai nút con. Một cây nhị phân tận dụng lợi thế của hai kiểu cấu trúc dữ liệu: một mảng đã sắp thứ tự và một danh sách liên kết (Linked List), do đó việc tìm kiếm sẽ nhanh như trong mảng đã sắp thứ tự và các thao tác chèn và xóa cũng sẽ nhanh bằng trong Linked List.

![Tree](img/tree.jpg)

### 1.1 Các khái niệm cơ bản về cây nhị phân

Một số khái niệm quan trọng liên quan tới cây nhị phân:

* **Đường**: là một dãy các nút cùng với các cạnh của một cây.
* **Nút gốc (Root)**: nút trên cùng của cây được gọi là nút gốc. Một cây sẽ chỉ có một nút gốc và một đường xuất phát từ nút gốc tới bất kỳ nút nào khác. Nút gốc là nút duy nhất không có bất kỳ nút cha nào.
* **Nút cha**: bất kỳ nút nào ngoại trừ nút gốc mà có một cạnh hướng lên một nút khác thì được gọi là nút cha.
Nút con: nút ở dưới một nút đã cho được kết nối bởi cạnh dưới của nó được gọi là nút con của nút đó.
Nút lá: nút mà không có bất kỳ nút con nào thì được gọi là nút lá.
* **Cây con**: cây con biểu diễn các con của một nút.
* **Truy cập**: kiểm tra giá trị của một nút khi điều khiển là đang trên một nút đó.
* **Duyệt**: duyệt qua các nút theo một thứ tự nào đó.
* **Bậc**: bậc của một nút biểu diễn số con của một nút. Nếu nút gốc có bậc là 0, thì nút con tiếp theo sẽ có bậc là 1, và nút cháu của nó sẽ có bậc là 2, …
* **Khóa (Key)**: biểu diễn một giá trị của một nút dựa trên những gì mà một thao tác tìm kiếm thực hiện trên nút.

### 1.2 Biểu diễn cây tìm kiếm nhị phân

Cây tìm kiếm nhị phân biểu diễn một hành vi đặc biệt. Con bên trái của một nút phải có giá trị nhỏ hơn giá trị của nút cha (của nút con này) và con bên phải của nút phải có giá trị lớn hơn giá trị của nút cha (của nút con này).

![Cây tìm kiếm nhị phân](img/tree2.jpg)

Chúng ta đang triển khai cây bởi sử dụng đối tượng nút và kết nối chúng thông qua các tham chiếu.

### 1.3 Nút (Node) trong cây tìm kiếm nhị phân

Một nút sẽ có cấu trúc như dưới đây. Nút có phần dữ liệu và phần tham chiếu tới các nút con bên trái và nút con bên phải.

```c++
struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
};
```

Trong một cây, tất cả các nút chia sẻ cùng một cấu trúc.

### 1.4 Hoạt động cơ bản trên cây tìm kiếm nhị phân

* **Chèn**: chèn một phần tử vào trong một cây/ tạo một cây.
* **Tìm kiếm**: tìm kiếm một phần tử trong một cây.
* **Duyệt tiền thứ tự**: duyệt một cây theo cách thức duyệt tiền thứ tự.
* **Duyệt trung thứ tự**: duyệt một cây theo cách thức duyệt trung thứ tự.
* **Duyệt hậu thứ tự**: duyệt một cây theo cách thức duyệt hậu thứ tự.

### 1.5 Hoạt động chèn trong cây tìm kiếm nhị phân

Bước chèn đầu tiên sẽ tạo thành cây. Tiếp đó là sẽ chèn từng phần tử vào trong cây. Đầu tiên chúng ta cần xác định vị trí chính xác của nó. Bắt đầu tìm kiếm từ nút gốc, sau đó nếu dữ liệu là nhỏ hơn giá trị khóa, thì tìm kiếm vị trí rỗng trong cây con bên trái và chèn dữ liệu. Nếu không nhỏ hơn, tìm vị trí rỗng trong cây con bên phải và chèn dữ liệu. 

### 1.6 Hoạt động tìm kiếm trong cây nhị phân

Mỗi khi một phần tử cần tìm kiếm: bắt đầu tìm kiếm từ nút gốc, sau đó nếu dữ liệu là nhỏ hơn giá trị khóa, thì tìm kiếm phần tử trong cây con bên trái; nếu không nhỏ hơn thì tìm kiếm phần tử trong cây con bên phải.

[TOP ^](#!)

## 2 Duyệt cây

### 2.1 Duyệt cây

Duyệt cây là một tiến trình để truy cập tất cả các nút của một cây và cũng có thể in các giá trị của các nút này. Bởi vì tất cả các nút được kết nối thông qua các cạnh (hoặc các link), nên chúng ta luôn luôn bắt đầu truy cập từ nút gốc. Do đó, chúng ta không thể truy cập ngẫu nhiên bất kỳ nút nào trong cây. Có ba phương thức mà chúng ta có thể sử dụng để duyệt một cây:

* Duyệt tiền thứ tự (Pre-order Traversal)
* Duyệt trung thứ tự (In-order Traversal)
* Duyệt hậu thứ tự (Post-order Traversal)

Nói chung, chúng ta duyệt một cây để tìm kiếm hay là để xác định vị trí phần tử hoặc khóa đã cho trong cây hoặc là để in tất cả giá trị mà cây đó chứa.

### 2.2 Duyệt tiền thứ tự trong cây nhị phân

Trong cách thức duyệt tiền thứ tự trong cây nhị phân, nút gốc được duyệt đầu tiên, sau đó sẽ duyệt cây con bên trái và cuối cùng sẽ duyệt cây con bên phải.

![Duyệt tiền thứ tự](img/duyet-tree1.jpg)

Ở hình ví dụ minh họa trên, A là nút gốc. Chúng ta bắt đầu từ A, và theo cách thức duyệt tiền thứ tự, đầu tiên chúng ta truy cập chính nút gốc A này và sau đó di chuyển tới nút con bên trái B của nó. B cũng được duyệt theo cách thức duyệt tiền thứ tự. Và tiến trình tiếp tục cho tới khi tất cả các nút đều đã được truy cập. Kết quả của cách thức duyệt tiền thứ tự cây này sẽ là: **A → B → D → E → C → F → G**

### 2.3 Duyệt trung thứ tự trong cây nhị phân

Trong cách duyệt này, cây con bên trái được truy cập đầu tiên, sau đó là nút gốc và sau đó là cây con bên phải. Bạn nên luôn luôn ghi nhớ rằng mỗi nút đều có thể biểu diễn một cây con.

Nếu một cây nhị phân được duyệt trung thứ tự, kết quả tạo ra sẽ là các giá trị khóa được sắp xếp theo thứ tự tăng dần.

![Duyệt trung thứ tự](img/duyet-tree2.jpg)

Ở hình ví dụ minh họa trên, A là nút gốc. Với phương thức duyệt trung thứ tự, chúng ta bắt đầu từ nút gốc A, di chuyển tới cây con bên trái B của nút gốc. Tại đây, B cũng được duyệt theo cách thức duyệt trung thứ tự. Và tiến trình tiếp tục cho đến khi tất cả các nút đã được truy cập. Kết quả của cách thức duyệt trung thứ tự cho cây trên sẽ là: **D → B → E → A → F → C → G**

### 2.4 Duyệt hậu thứ tự trong cây nhị phân
Trong cách thức duyệt hậu thứ tự trong cây nhị phân, nút gốc của cây sẽ được truy cập cuối cùng, do đó bạn cần chú ý. Đầu tiên, chúng ta duyệt cây con bên trái, sau đó sẽ duyệt cây con bên phải và cuối cùng là duyệt nút gốc.

![Duyệt hậu thứ tự](img/duyet-tree3.jpg)

Ở hình ví dụ minh họa trên, A là nút gốc. Chúng ta bắt đầu từ A, và theo cách duyệt hậu thứ tự, đầu tiên chúng ta truy cập cây con bên trái B. B cũng được duyệt theo cách thứ duyệt hậu thứ tự. Và tiến trình sẽ tiếp tục tới khi tất cả các nút đã được truy cập. Kết quả của cách thức duyệt hậu thứ tự của cây con trên sẽ là: **D → E → B → F → G → C → A**

[TOP ^](#!)

## 3 Cây tìm kiếm nhị phân

### 3.1 Cây tìm kiếm nhị phân (Binary Search Tree)

Một cây tìm kiếm nhị phân (Binary Search Tree – viết tắt là BST) là một cây mà trong đó tất cả các nút đều có các đặc điểm sau:

* Cây con bên trái của một nút có khóa (key) nhỏ hơn hoặc bằng giá trị khóa của nút cha (của cây con này).
* Cây con bên phải của một nút có khóa lớn hơn hoặc bằng giá trị khóa của nút cha (của cây con này).

Vì thế có thể nói rằng, một cây tìm kiếm nhị phân (BST) phân chia tất cả các cây con của nó thành hai phần: cây con bên trái và cây con bên phải và có thể được định nghĩa như sau:

`left_subtree (keys) ≤ node (key) ≤ right_subtree (keys)`

### 3.2 Biểu diễn cây tìm kiếm nhị phân

Cây tìm kiếm nhị phân (BST) là một tập hợp bao gồm các nút được sắp xếp theo cách để chúng có thể duy trì hoặc tuân theo các đặc điểm của cây tìm kiếm nhị phân. Mỗi một nút thì đều có một khóa và giá trị liên kết với nó. Trong khi tìm kiếm, khóa cần tìm được so sánh với các khóa trong cây tìm kiếm nhị phân (BST) và nếu tìm thấy, giá trị liên kết sẽ được thu nhận.

Ví dụ một cây tìm kiếm nhị phân (BST):

![Binary Search Tree](img/BST.jpg)

Từ hình ví dụ minh họa trên ta thấy rằng, khóa của nút gốc có giá trị 27 và tất cả khóa bên trái của cây con bên trái đều có giá trị nhỏ hơn 27 này và tất cả các khóa bên phải của cây con bên phải đều có giá trị lớn hơn 27.

### 3.3 Nút (Node) trong cây tìm kiếm nhị phân

Một nút có một vài dữ liệu, tham chiếu tới các nút con bên trái và nút con bên phải của nó.

``` c++
struct node {
   int data;   
   struct node *leftChild;
   struct node *rightChild;
};
```

### 3.4 Hoạt động cơ bản trên cây tìm kiếm nhị phân

* **Hoạt động tìm kiếm**: tìm kiếm một phần tử trong một cây.
* **Hoạt động chèn**: chèn một phần tử vào trong một cây.
* **Hoạt động duyệt tiền thứ tự:** duyệt một cây theo cách thức duyệt tiền thứ tự.
* **Hoạt động duyệt trung thứ tự**: duyệt một cây theo cách thứ duyệt trung thứ tự.
* **Hoạt động duyệt hậu thứ tự**: duyệt một cây theo cách thức duyệt hậu thứ tự.

### 3.5 Hoạt động tìm kiếm trong cây tìm kiếm nhị phân

Mỗi khi một phần tử được tìm kiếm: bắt đầu tìm kiếm từ nút gốc, sau đó nếu dữ liệu là nhỏ hơn giá trị khóa (key), thì sẽ tìm phần tử ở cây con bên trái; nếu lớn hơn thì sẽ tìm phần tử ở cây con bên phải.

### 3.6 Hoạt động chèn trong cây tìm kiếm nhị phân

Mỗi khi một phần tử được chèn: đầu tiên chúng ta cần xác định vị trí chính xác của phần tử này. Bắt đầu tìm kiếm từ nút gốc, sau đó nếu dữ liệu là nhỏ hơn giá trị khóa (key), thì tìm kiếm vị trí còn trống ở cây con bên trái và chèn dữ liệu vào đó; nếu dữ liệu là nhỏ hơn thì tìm kiếm vị trí còn sống ở cây con bên phải và chèn dữ liệu vào đó.

[TOP ^](#!)

## 4 Cây AVL

### 4.1 Cây AVL

Điều gì xảy ra nếu dữ liệu nhập vào cây tìm kiếm nhị phân (BST) là ở dạng đã được sắp thứ tự (tăng dần hoặc giảm dần). Nó sẽ trông giống như sau:

![Cây AVL](img/AVL1.jpg)

Nói chung, hiệu suất trường hợp xấu nhất của cây tìm kiếm nhị phân (BST) gần với các giải thuật tìm kiếm tuyến tính, tức là Ο(n). Với dữ liệu thời gian thực, chúng ta không thể dự đoán mẫu dữ liệu và các tần số của nó. Vì thế, điều cần thiết phát sinh ở đây là để cân bằng cây tìm kiếm nhị phân đang tồn tại.

Cây AVL (viết tắt của tên các nhà phát minh Adelson, Velski và Landis) là cây tìm kiếm nhị phân có độ cân bằng cao. Cây AVL kiểm tra độ cao của các cây con bên trái và cây con bên phải và bảo đảm rằng hiệu số giữa chúng là không lớn hơn 1. Hiệu số này được gọi là Balance Factor (Nhân tố cân bằng).

Dưới đây là hình ví dụ minh họa ba cây, trong đó cây đầu tiên là cân bằng, cây thứ hai và thứ ba là không cân bằng.

![Cây AVL](img/AVL2.jpg)

Trong cây thứ hai, cây con bên trái của C có độ cao là 2 và cây con bên phải có độ cao là 0, do đó hiệu số là 2. Trong cây thứ ba, cây con bên phải của A có độ cao là 2 và cây con bên trái có độ cao là 0, do đó hiệu số cũng là 2. Trong khi cây AVL chỉ chấp nhận hiệu số (hay Nhân tố cân bằng) là 1.

`BalanceFactor = height(left-sutree) − height(right-sutree)`

Nếu hiệu số giữa độ cao của các cây con bên trái và cây con bên phải là lớn hơn 1 thì cây được cân bằng bởi sử dụng một số kỹ thuật quay AVL dưới đây.

### 4.2 Kỹ thuật quay cây AVL

Để làm cho cây tự cân bằng, một cây AVL có thể thực hiện 4 loại kỹ thuật quay sau:

* Kỹ thuật quay trái
* Kỹ thuật quay phải
* Kỹ thuật quay trái-phải
*Kỹ thuật quay phải-trái

Hai kỹ thuật quay đầu tiên là các kỹ thuật quay đơn và hai kỹ thuật quay còn lại là các kỹ thuật quay ghép.

[Chi tiết kỹ thuật quay](https://hoclaptrinh.vn/tutorial/cau-truc-du-lieu-amp-giai-thuat-55-bai/cay-avl-trong-cau-truc-du-lieu-va-giai-thuat)

[TOP ^](#!)

## 5 Cây SPLAY

### 5.1 Cây SPLAY

* Là cây tìm kiếm nhị phân.
* Mỗi khi truy cập vào mộ nút trên cây (thêm hoặc xoá) thì nút mới truy nhập sẽ được tự động chuyển thành gốc của cây mới.
* Các nút được truy cập thường xuyên sẽ ở gần gốc.
* Để dịch chuyển nút ta dung các phép xoay giống với trong AVL tree.
* Các nút nằm trên đường đi từ gốc tới nút mới truy cập sẽ chịu ảnh hưởng của các phép xoay.

### 5.2 Kỹ thuật quay cây SPLAY

Có 2 phép quay trong cây SPLAY , đó là :

* Kỹ thuật xoay đơn
* Kỹ thuật xoay kép

[TOP ^](#!)

## 6 Cây khung

### 6.1 Cây khung (Spanning Tree)

Một cây khung là một tập con của Grahp G mà có tất cả các đỉnh được bao bởi số cạnh tối thiểu nhất. Vì thế, một cây khung sẽ không hình thành một vòng tuần hoàn và nó cũng không thể bị ngắt giữa chừng.

Từ định nghĩa trên ta có thể kết luận rằng mỗi Graph G tuần hoàn sẽ có ít nhất một cây khung. Một Graph G bị ngắt giữa chừng sẽ không có bất kỳ cây khung nào.

Dưới đây là hình ví dụ minh họa cho một Grahp G và các cây khung của nó:

![Cây khung (Spanning Tree)](img/spanning-tree.jpg)

Ở trên chúng ta có 3 cây khung của một đồ thị tuần hoàn. Một đồ thị tuần hoàn có thể có tối đa n^(n-2) cây khung, trong đó n là số nút. Trong ví dụ trên, n là 3 do đó 3^(3−2) = 3 cây khung.

### 6.2 Thuộc tính chung của cây khung (Spanning Tree)

Bây giờ chúng ta hiểu rằng một Graph có thể có nhiều hơn một cây khung. Phần dưới đây là một số thuộc tính của cây khung của Graph G tuần hoàn đã cho:

* Một Grahp G tuần hoàn có thể có nhiều hơn một cây khung.
* Tất cả các cây khung của một Graph G đều có cùng số cạnh và số đỉnh.
* Cây khung không có bất kỳ vòng tuần hoàn nào.
* Việc xóa một cạnh từ cây khung sẽ làm cho Grahp là không tuần hoàn.
* Thêm một cạnh vào cây khung sẽ tạo nên một vòng tuần hoàn.

### 6.3 Thuộc tính toán học của cây khung (Spanning Tree)

* Cây khung có n-1 cạnh, trong đó n là số nút (đỉnh).
* Từ một Graph tuần hoàn, bằng việc xóa đi tối đa e-n+1 cạnh, chúng ta có thể xây dựng một cây khung.
* Một Grahp tuần hoàn có thể có tối đa n^(n-2) cây khung.

### 6.4 Ứng dụng của cây khung (Spanning Tree)

Về cơ bản cây khung được sử dụng để tìm các đường ngắn nhất để kết nối tất cả các nút trong một Graph. Các ứng dụng phổ biến của cây khung là:

* Lập kế hoạch mạng dân sự
* Giao thức định tuyến mạng máy tính
* Cluster Analysis

Chúng ta tìm hiểu ví dụ đơn giản sau để hiểu các ứng dụng này. Bạn thử tưởng tượng một mạng internet trong thành phố là một hình Graph lớn và bây giờ kế hoạch đặt ra là triển khai các đường dây mạng sao cho với độ dài dây là ngắn nhất mà vẫn có thể kết nối được tất cả các nút trong thành phố. Đó là một ví dụ giải thích cho ứng dụng của cây khung.

### 6.5 Cây khung nhỏ nhất (Minimum Spanning Tree – MST)

Trong một đồ thị có trọng số (Weighted Graph), một cây khung nhỏ nhất là cây khung mà có trọng số (weight) nhỏ nhất trong tất cả các cây khung của Grahp này. Trong đời sống thực, weight (trọng số) ở đây có thể là khoảng cách (distance), độ nghẽn (congestion), độ tải (traffic load) hoặc bất kỳ giá trị nào có thể được biểu diễn thành các cạnh.

### 6.6 Giải thuật cho cây khung nhỏ nhất

* [Giải thuật cây khung nhỏ nhất của Kruskal](#1)

* [Giải thuật cây khung nhỏ nhất của Prim](#1)

Hai giải thuật này đều thuộc loại [Giải thuật tham lam (Greedy Algorithms)](#1).

[TOP ^](#!)

## 7 Heap

### 7.1 Cấu trúc dữ liệu Heap

Cấu trúc dữ liệu Heap là một trường hợp đặc biệt của cấu trúc dữ liệu cây nhị phân cân bằng, trong đó khóa của nút gốc được so sánh với các con của nó và được sắp xếp một cách phù hợp. Nếu α có nút con β thì:

`key(α) ≥ key(β)`

Khi giá trị của nút cha lớn hơn giá trị của nút con, thì thuộc tính này tạo ra một Max Heap. Dựa trên tiêu chí này, một Heap có thể là một trong hai kiểu sau:

`Với dữ liệu đầu vào → 35 33 42 10 14 19 27 44 26 31`

* **Min-Heap**: ở đây giá trị của nút gốc là nhỏ hơn hoặc bằng các giá trị của các nút con.

![Min Heap](img/min-heap.jpg)

* **Max-Heap**: ở đây giá trị của nút gốc là lớn hơn hoặc bằng giá trị của các nút con.

![Max Heap](img/max-heap.jpg)

### Giải thuật xây dựng Max Heap

Chúng ta sẽ suy ra một giải thuật cho Max Heap bằng việc chèn một phần tử tại một thời điểm. Tại bất cứ thời điểm nào, Heap đều phải duy trì (tuân theo) thuộc tính của nó. Trong quá trình chèn, chúng ta cũng giả sử rằng chúng ta đang chèn một nút vào trong HEAPIFIED Tree.

**Bước 1**: Tạo một nút mới tại vị trí cuối cùng của Heap.

**Bước 2**: Gán giá trị mới cho nút này.

**Bước 3**: So sánh giá trị của nút con với giá trị cha.

**Bước 4**: Nếu giá trị của cha là nhỏ hơn con thì tráo đổi chúng.

**Bước 5**: Lặp lại bước 3 và 4 cho tới khi vẫn duy trì thuộc tính của Heap.

**Ghi chú**: Trong giải thuật xây dựng Min Heap, giá trị của nút cha sẽ là nhỏ hơn giá trị của các nút con.

![Max Heap](img/max-heap1.gif)

### Giải thuật xóa trong Max Heap

Hoạt động xóa trong Max (hoặc Min) Heap luôn luôn diễn ra tại nút gốc và để xóa giá trị Lớn nhất (hoặc Nhỏ nhất).

**Bước 1**: Xóa nút gốc.

**Bước 2**: Di chuyển phần tử cuối cùng có bậc thấp nhất lên nút gốc.

**Bước 3**: So sánh giá trị của nút con này với giá trị của cha.

**Bước 4**: Nếu giá trị của cha là nhỏ hơn của con thì **tráo đổi** chúng.

**Bước 5**: Lặp lại bước 3 và 4 cho tới khi vẫn duy trì thuộc tính của Heap.

![Max Heap](img/max-heap2.gif)

[TOP ^](#!)
