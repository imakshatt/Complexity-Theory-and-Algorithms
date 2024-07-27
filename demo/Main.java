import java.util.Random;

class Main{ 
    //
    public static void main(String[] args) {
        int[] size = new int[] {10000,50000,100000};
		ArrayType[] arrayType = new ArrayType[] {ArrayType.Ascending,ArrayType.Descending,ArrayType.Random};
        PivotTypeEnum[] pivotType = new PivotTypeEnum[] {PivotTypeEnum.firstIndex,PivotTypeEnum.endIndex,PivotTypeEnum.Random,PivotTypeEnum.MiddleIndex};

        for (int i = 0; i < size.length; i++) {
			for (int j = 0; j < arrayType.length; j++) {
				for (int j2 = 0; j2 < pivotType.length; j2++) {
                int[] arr = new int[0];
				System.out.println("");
				
				switch (arrayType[j]) {
				case Ascending: {
					System.out.println("Ascending Order Start : - " + size[i]);
					arr = arrayGen(size[i],true);
					break;
				}
				case Descending:{
					System.out.println("Descending Order Start : - " + size[i]);
					arr = arrayGen(size[i],false);
					break;
				}
				case Random:{
					System.out.println("Random Order Start : - " + size[i]);
					arr = randomArrayGen(size[i]);
					break;
				}
				default:
					throw new IllegalArgumentException("Unexpected value: " + arrayType[j]);
				}

                  System.out.println("");
                 System.out.println( "Using Pivot Order : " + pivotType[j2]);
               
                 long startneno = System.currentTimeMillis();
                 int[] v = quickSort(arr, 0, arr.length - 1,pivotType[j2]);
                 long endneno = System.currentTimeMillis();
               
                 System.out.println("quickSort in  seconds: "+ (endneno-startneno) / 1000F);

                 printArrray(arr);
                 System.out.println("");
                 System.out.println("---------------------------------------------");
                }
			}
				
		}


      
    }

    public static void printArrray(int[] arr) {
		for (int i = 0; i < 100; i++) {
			System.out.print(arr[i] +",");
		}
	}

    	
	public static int[] randomArrayGen(int size) {
		int[] arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = (int) (Math.random() * (size - 0 + 1));
		}
		return arr;
	}

    public static int[] arrayGen(int size,boolean isSorted) {
		int[] arr = new int[size];
		if(isSorted) {
			for (int i = 0; i < size; i++) {
				arr[i] = i;
			}
		}else {
			for (int i = 0; i < size; i++) {
				arr[i] = size - i;
			}
		}
		return arr;
	}

    private static void swapArray(int[] arr,int i,int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
    private static Random rand = new Random();
    public static int[] quickSort(int[] arr,int firstIndex,int endIndex,PivotTypeEnum p) {
		int i = firstIndex;
		int j = endIndex;
		
        int pivotIndex = 0;
        if(p == PivotTypeEnum.firstIndex){
            pivotIndex = firstIndex;
        } else if(p == PivotTypeEnum.endIndex){
            pivotIndex = endIndex;
        }
         else if(p == PivotTypeEnum.MiddleIndex){
             pivotIndex = (firstIndex + endIndex) / 2;
        }
         else if(p == PivotTypeEnum.Random){
            int k =  rand.nextInt(firstIndex, endIndex);
             pivotIndex = k;
        }
		int pivot = arr[pivotIndex]; // (firstIndex + endIndex) / 2 middle ,
	
		while (i < j) {
			while (arr[i] < pivot) {
				i++;
			}
			while (arr[j] > pivot) {
				j--;
			}
			if (i <= j) {
				swapArray(arr,i, j);
				i++;
				j--;
			}
		}
	
		if (firstIndex < j) {
			quickSort(arr,firstIndex, j,p);
		}
		if (i < endIndex) {
			quickSort(arr,i, endIndex,p);
		}
		return arr;
	}


    public enum ArrayType{
		Ascending,
		Descending,
		Random
	}

    public enum PivotTypeEnum{
		firstIndex,
		endIndex,
		Random,
        MiddleIndex
	}
}