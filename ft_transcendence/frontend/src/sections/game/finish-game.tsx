import Link from "next/link";

interface IFinishGame {
  score: number;
  message: string
}

export default function FinishGame({ score, message }: IFinishGame) {
  return (
    <div className="fixed top-0 left-0 right-0 bottom-0 w-full h-screen z-50 overflow-hidden bg-gray-900 opacity-80 flex flex-col items-center justify-center">
      <div>
        <h3 className="text-4xl text-center">{message}</h3>
        <hr className="w-full my-6" />
        <h6 className="text-4xl">
          Your Score: <span className="font-bold">{score}</span>
        </h6>
        <Link href={"/"}>Back To Home</Link>
      </div>
    </div>
  );
}
