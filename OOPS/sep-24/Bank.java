class InsuffientFundException extends Exception{
	InsuffientFundException(){
		super("Insuffient fund amount in balance.");
	}
}

class BankAccount{

	private int balance;

	BankAccount(){
		balance = 50;
	}
	BankAccount(int balance){
		this.balance = balance;
	}

	public void withdraw(int amount) throws InsuffientFundException{
		if(balance-amount<50){
			throw new InsuffientFundException();
		}
	}

}

class Runnable {
	public static void main(String args[]){
		BankAccount account = new BankAccount(60);
		try{
			account.withdraw(50);
		}catch(InsuffientFundException e){
			System.out.println(e);
		}
		
	}
}