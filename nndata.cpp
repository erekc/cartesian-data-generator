#include "nndata.h"

NNData::NNData(int numSamples, int dimension) :
    numSamples(numSamples), dimension(dimension), chartView(std::make_shared<ChartView>()){
    std::vector<std::size_t> dataShape = {static_cast<size_t>(this->numSamples), static_cast<size_t>(this->dimension)};
    this->data = new xt::xarray<double, xt::layout_type::row_major>(dataShape);
    std::cout << "NNData Constructor" << std::endl;
}

NNData::~NNData(){
    if (this->data){
        delete this->data;
    }
    std::cout << "NNData Destructor" << std::endl;
}

NNData::NNData(const NNData& source){
    std::vector<std::size_t> dataShape = {static_cast<size_t>(source.numSamples), static_cast<size_t>(source.dimension)};
    this->data = new xt::xarray<double, xt::layout_type::row_major>(dataShape);
    *(this->data) = *(source.data);
    this->dimension = source.dimension;
    this->numSamples = source.numSamples;
    this->chartView = source.chartView;
    std::cout << "NNData Copy Constructor" << std::endl;
}

NNData& NNData::operator=(const NNData &source){
    if (this == &source){
        return *this;
    }

    if (this->data){
        delete this->data;
    }

    std::vector<std::size_t> dataShape = {static_cast<size_t>(source.numSamples), static_cast<size_t>(source.dimension)};
    this->data = new xt::xarray<double, xt::layout_type::row_major>(dataShape);
    *(this->data) = *(source.data);
    this->dimension = source.dimension;
    this->numSamples = source.numSamples;
    this->chartView = source.chartView;
    std::cout << "NNData Copy Assignment" << std::endl;

    return *this;
}

NNData::NNData(NNData&& source){
    this->data = source.data;
    this->dimension = source.dimension;
    this->numSamples = source.numSamples;
    this->chartView = source.chartView;
    source.data = nullptr;
    source.dimension = 0;
    source.numSamples = 0;
    std::cout << "NNData Move Constructor" << std::endl;
}

NNData& NNData::operator=(NNData&& source){
    if (this == &source){
        return *this;
    }

    if (this->data){
        delete this->data;
    }

    this->data = source.data;
    this->dimension = source.dimension;
    this->numSamples = source.numSamples;
    this->chartView = source.chartView;
    source.data = nullptr;
    source.dimension = 0;
    source.numSamples = 0;
    std::cout << "NNData Move Assignment" << std::endl;

    return *this;
}

void NNData::generateData(){
    *(this->data) = std::move(xt::random::randn<double>({this->numSamples, this->dimension}));
    this->chartView->addSeriesToList("nndata", *(this->data));
    this->chartView->setRubberBand(QChartView::RectangleRubberBand);
}

void NNData::showData(){
    this->chartView->plotChart();
    this->chartView->showChart();
}
