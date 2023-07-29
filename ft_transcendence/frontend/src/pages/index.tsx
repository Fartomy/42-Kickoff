import { ReactNode } from "react";
import LeaderBoard from "@/components/LeaderBoard";
import MatchHistory from "@/components/MatchHistory";
import DashboardLayout from "@/layouts/DashboardLayout";

Home.getLayout = (page: ReactNode) => <DashboardLayout>{page}</DashboardLayout>;

export default function Home() {
  return (
    <div className="flex gap-3 flex-wrap lg:flex-nowrap">
      <LeaderBoard />
      <MatchHistory />
    </div>
  );
}
