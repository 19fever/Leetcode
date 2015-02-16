public class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> ret = new ArrayList<Integer>(rowIndex + 1);

        for (int i = 0; i < rowIndex + 1; i++) {
            ret.add(0);
        }
        ret.set(0,1);
        for (int i = 1; i <= rowIndex; i++) {
            ret.set(i,1);
            for (int j = i - 1; j > 0; j--) {
                ret.set(j, ret.get(j)+ret.get(j-1));
            }
        }

        return ret;
    }
}
