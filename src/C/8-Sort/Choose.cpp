#include "iostream"
#include "../2-LinearList/List/ListBasic.cpp"

using namespace std;

#define MAXSIZE 100

void printf(int R[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << R[i] << " ";
    }
    cout << endl;
}

/**
 * 直接选择排序
 * 每次循环结束能保证前 i 个序列有序，且都在最终位置。
 * 稳定性：不稳定 ×，因为有“交换”。如 4 3 4 1 5，1 会和第一个 4 交换，导致这两个 4 相对位置改变。
 * 时间复杂度：
 *      简单选择排序中，元素的移动次数很少，不会超过3(n-1)次，最好的情况是移动0次。此时对应的表已经有序。
 *      但元素间比较的次数与序列的初始状态无关，始终是n(n-1)/2次，因此时间复杂度始终是O(n^2)
 * 空间复杂度：
 *      算法所需的辅助存储空间不随待排序序列规模的变化而变化，是个常量，故 O(1)
 * @param R 数组
 * @param n 数组长度
 */
void selectSort(int R[], int n) {
    int i, j, k;
    int temp;
    for (i = 0; i < n; i++) {
        k = i;
        //找到从 i 到 n - 1 序列中的最小值
        for (j = i + 1; j < n; j++) {
            if (R[k] > R[j]) {
                k = j;
            }
        }
        temp = R[i];
        R[i] = R[k];
        R[k] = temp;
    }
}

//使用无头结点的单链表实现简单选择排序，令元素递增
//因为是无头结点，所以最好将新结点直接插入到链头，且为了使元素递增，应找到当前链表的最大结点插入链头
List* selectSort(List *&list)
{
    //为了代码清晰，多设几个结点
    //l代表没排过序的链表的链头，max_prior代表最大结点的前驱，max表示最大结点，p_prior代表工作结点的前驱，p代表工作结点
    List *l = list, *max_prior, *max, *p_prior, *p;
    list = nullptr;
    while (l != nullptr)
    {
        //每次循环初始将工作结点和最大结点都设为链头，它们的前驱为null
        p = max = l;
        p_prior = max_prior = nullptr;
        while (p != nullptr)
        {
            //如果当前结点比max结点大，令max为p，同时修改其max_prior
            if (p->val > max->val)
            {
                max_prior = p_prior;
                max = p;
            }
            p_prior = p;
            p = p->next;
        }
        //如果是当前链表的头结点最大，直接接到新链表前面
        if (max == l)
        {
            l = l->next;
        } else {
        //否则还需要更改其前驱
            max_prior->next = max->next;
        }
        max->next = list;
        list = max;
    }
}


/**
 * 完成在数组 R[low] 到 R[high] 的范围内对在位置 low 上的结点进行调整
 * 在外部从二叉树的下层调整到上层，从而保证每个顶点为根结点的树都是大顶堆
 * 同时，堆也支持插入操作，堆堆进行插入操作时，先将新结点放在堆的末端，再堆这个新结点向上执行调整操作
 * 记堆（完全二叉树）结点从 0 开始
 * @param R 数组
 * @param low 被调整的结点序号
 * @param high 数组上限，即无序序列的最后一个结点
 */
void sift(int R[], int low, int high) {
    //R[j] 是 R[i] 的左孩子结点
    int i = low, j = 2 * i + 1;
    //记录根结点
    int temp = R[i];
    //如果根结点有左孩子 进入循环
    while (j <= high) {
        //选右孩子和左孩子更大的那一个
        //如果根结点有右孩子且右孩子大于左孩子
        if (j + 1 <= high && R[j] < R[j + 1]) {
            //则把 j 指向右孩子
            ++j;
        }
        //将左右孩子更大的那个与根节点比较 如果根结点小于它
        if (temp < R[j]) {
            //将孩子结点 R[j] 调整到双亲结点 R[i] 的位置上，覆盖就可以不必在这里交换
            //直到调整到某个位置 i， temp 大于 R[i] 的左右孩子时循环终止，此时再交换
            R[i] = R[j];
            //由于更改了i和j这一对父子，可能对下面的树也造成影响，所以修改 i 和 j 的值，从 j 的子树递归向下调整
            i = j;
            j = 2 * i + 1;
        } else {
            //一直调整最开始这个 R[i] 值，直到它满足堆定义，即大于其所有孩子结点值
            break;
        }
    }
    //将被调整结点的值放入最终位置
    R[i] = temp;
}

/**
 * 堆排序
 * 以大顶堆为例，由大顶堆的定义可知，每一个根结点都大于它的两个子结点，因此将一个无序序列调整为
 * 一个堆，就可以找出这个序列的最大值，然后将找出的这个值交换到序列的最后，这样，有序序列关键字增加一个，无序序列
 * 关键字减少一个，对新的无序序列重复这样的操作就实现了排序。核心算法即为将一个完全二叉树转换为大顶堆。
 * 稳定性：不稳定 × 如 1 2_1 2_2 第一次循环：1 跟左子节点 2_1 互换后，又和 2_2 交换完成一次
 * 循环，固定 2_1 到最后一位。第二次循环：对 2_2 1 堆排序，得到 1 2_2 2_1
 * 时间复杂度：
 *      对于函数 sift()，显然 j 走了一条从当前结点到叶子结点的路径，完全二叉树的高度为 log2_(n+1)，
 *      即对每个节点调整的时间复杂度为 O(log2_n)，对于函数 heapSort()，基本操作总次数应该是两个for循环
 *      中的基本操作次数之和，第一个循环（建堆）的基本操作次数为 O(n) 第二个循环的基本操作次数为
 *      (n-1) * O(log2_n)，因此整个算法的基本操作次数为 O(nlog2_n)
 *      具体分析见 https://www.zhihu.com/question/20729324
 *      在这里对某个结点走向叶子结点的操作数进行了简化，即令其等于从根结点走向叶子结点的操作数，由此也可得出堆排序
 *      最差情况下的时间复杂度也是 O(nlog2_n)
 * 空间复杂度：
 *      算法所需的辅助存储空间不随待排序序列规模的变化而变化，是个常量，故 O(1)
 * @param R 数组
 * @param n 数组长度
 */
void heapSort(int R[], int n) {
    int i;
    int temp;
    //建立初始堆 检查有右孩子的结点 从下层到上层 从右到左
    for (i = n / 2 - 1; i >= 0; i--) {
        sift(R, i, n - 1);
    }
    //n - 1 次循环即可
    for (i = n - 1; i >= 1; i--) {
        //将根结点（最大值）与当前堆的最后一个结点互换，即将根结点放入最终位置
        //为什么是最后一个结点不是其它结点？因为要把根结点放到数组中最大的位置啊
        //互换后，堆中元素 - 1，构成一个以 R[i] 为根的新堆，再执行 sift()，还会出现一个新的根结点
        temp = R[0];
        R[0] = R[i];
        R[i] = temp;
        //固定好一个后，数组顶端为 i - 1
        sift(R, 0, i - 1);
    }
}

//判断一个数组A[0...n-1]是否是小顶堆
int isMinHeap(int array[], int n)
{
    //如果有左孩子 即单分支结点 需要与双分支结点的情况分开讨论
    if (n % 2 == 0)
    {
        if (array[(n - 1) / 2] > array[n - 1])
        {
            return 0;
        }
        for (int i = (n - 1) / 2 - 1; i >= 0; i--)
        {
            if (array[i] > array[2 * i + 1] || array[i] > array[2 * i + 2])
            {
                return 0;
            }
        }
    //双分支结点
    } else {
        for (int i = (n - 1) / 2; i >= 0; i--)
        {
            if (array[i] > array[2 * i + 1] || array[i] > array[2 * i + 2])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int array[MAXSIZE] = {49, 38, 65, 97, 76, 13, 27, 40};
    int n = 8;
    List *list = (List*) malloc(sizeof (List));
    initial_head(list, array, n);
    list = list->next;
}